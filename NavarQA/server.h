//==================================================================
// include guard
#ifndef _SERVER_H_
#define _SERVER_H_

//==================================================================
// Inclusi�n de dependencias
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <math.h>
#include "NatNetTypes.h"
#include "NatNetServer.h"
#include <mmsystem.h> // quiz�s no sirva para nada aqu�
#include "NATUtils.h"

#define POINTERR 1
#define FEMURR 3
#define TIBIAA 2
#define GAFASS 4
#define BROCAA 6

#pragma warning( disable : 4996 )

namespace CustomCameraLibrary {
	using namespace CCL;

	void BuildDescription(sDataDescriptions* pDescription);
	void SendDescription(sDataDescriptions* pDescription);
	void FreeDescription(sDataDescriptions* pDescription);
	void BuildFrame(long FrameNumber, sDataDescriptions* pDataDescriptions, sFrameOfMocapData* pOutFrame);
	void SendFrame(sFrameOfMocapData* pFrame);
	void FreeFrame(sFrameOfMocapData* pFrame);
	void resetServer();
	int CreateServer(int iConnectionType);
	int HiResSleep(int msecs);
	int StartServer();
	void WriteW(string s);
	void StreamFrame();
	BodyR getBdrigid(char * name, int nrig);

	// callbacks
	void __cdecl MessageHandler(int msgType, char* msg);
	int __cdecl RequestHandler(sPacket* pPacketIn, sPacket* pPacketOut, void* pUserData);

	// playing thread
	int StartPlayingThread();
	int StopPlayingThread();
	DWORD WINAPI PlayingThread_Func(void *dummy);

	NatNetServer* theServer;    				///< Instancia del servidor 
	sDataDescriptions descriptions; 			///< Descripci�n de los datos que se van a enviar (Descripci�n de los cuerpos r�gidos y sus caracter�sticas).
	long g_lCurrentFrame = 0;					///< Contador de Frames que va enviando el servidor al cliente.
	bool g_bPlaying = false;					///< Indicador que muestra si el servidor esta enviando datos al cliente.
	DWORD PlayingThread_ID = NULL;				///< Id del hilo que ejecuta el servidor.
	HANDLE PlayingThread_Handle = NULL;			///< Manejador del hilo que ejecuta el servidor.
	int counter = 0;							///< Sin uso importante. Puede ser borrado.	
												//	int counter2 = 0;						
												//	float fCounter = 0.0f;
	unsigned int DataPort = 1511;				///< Puerto utilizado para el env�o de datos.
	unsigned int CommandPort = 1510;			///< Puerto utilizado para la recepci�n de comandos desde el cliente.
	unsigned long lAddresses[10];

	//==================================================================
	// Definicion de asociaciones
#define STREAM_RBS 1				///< NO UTILIZADO 
#define STREAM_MARKERS 1			///< NO UTILIZADO 
#define STREAM_SKELETONS 0			///< NO UTILIZADO 
#define STREAM_LABELED_MARKERS 0	///< NO UTILIZADO 

	stringstream s;						///< Utilizado para ir concatenando texto y mostrarlo cuando se inicia el servidor.
	cv::Mat pic = cv::Mat::zeros(800, 600, CV_8UC3); ///< imagen que se muestra de color negro en la ventana que sale al iniciar el servidor.
	int y0 = 50;						///< Posici�n inicial del primer texto que aprece en la ventana que sale cuando se inicia el servidor.
	int dy = 20;						///< incremento inicial del primer texto que aprece en la ventana que sale cuando se inicia el servidor.
	int i = 0;

	/**
	* puntero al almacen de cuerpos r�gidos, de aqu� se pueden acceder despu�s de ser detectados.
	* @see CustomCameraLibrary::joskstra()
	*/
	BodyR *rigid;

	//Mat_<double> oldBr;
	HANDLE sSemaphore;		///< Sem�foro que se utiliza para sincronizar datos obtenidos desde el hilo principal con el hilo donde corre el servidor y se env�an los datos al cliente.
	HANDLE brSemaphore;		///< Sem�foro que se utiliza para sincronizar datos obtenidos desde el hilo principal con el hilo donde corre el servidor y se env�an los datos al cliente.
	DWORD sResult;

	/**
	* cantidad de cuerpos r�gidos detectados.
	* @see CustomCameraLibrary::joskstra()
	*/
	int nbr;

int CreateServer(int iConnectionType) {
		// release previous server
		if (theServer) {
			theServer->Uninitialize();
			delete theServer;
		}

		// create new NatNet server
		theServer = new NatNetServer(iConnectionType);

		// optional - use old multicast group
		//theServer->SetMulticastAddress("224.0.0.1");

		// print version info
		unsigned char ver[4];
		theServer->NatNetVersion(ver);
		s.str("");
		printf("NatNet Server (NatNet ver. %d.%d.%d.%d)\n", ver[0], ver[1], ver[2], ver[3]);
		WriteW(s.str());
		s << "NatNet Server (NatNet ver. " << to_string(ver[0]) << "." << to_string(ver[1]) << "." << to_string(ver[2]) << "." << to_string(ver[3]) << ")";
		WriteW(s.str()); // solo para escribir en la ventana.
		
						 // set callbacks
		theServer->SetErrorMessageCallback(MessageHandler);
		theServer->SetVerbosityLevel(Verbosity_Debug);
		theServer->SetMessageResponseCallback(RequestHandler);	    // Handles requests from the Client

																	// get local ip addresses
		char szIPAddress[128];
		in_addr MyAddress[10];
		int nAddresses = NATUtils::GetLocalIPAddresses2((unsigned long *)&MyAddress, 10);
		if (nAddresses < 1) {
			printf("Unable to detect local network.  Exiting");
			return 1;
		}
		for (int i = 0; i < nAddresses; i++) {
			sprintf(szIPAddress, "%d.%d.%d.%d", MyAddress[i].S_un.S_un_b.s_b1, MyAddress[i].S_un.S_un_b.s_b2, MyAddress[i].S_un.S_un_b.s_b3, MyAddress[i].S_un.S_un_b.s_b4);
			printf("IP Address : %s\n", szIPAddress);
			s.str("");
			s << "IP Address : " << szIPAddress;
			WriteW(s.str());
		}
		// select first
		// sprintf(szIPAddress, "%d.%d.%d.%d", MyAddress[0].S_un.S_un_b.s_b1, MyAddress[0].S_un.S_un_b.s_b2, MyAddress[0].S_un.S_un_b.s_b3, MyAddress[0].S_un.S_un_b.s_b4);

		//**************************************
		// IP DONDE CORRER� EL SERVIDOR
		//**************************************
		sprintf(szIPAddress, "%d.%d.%d.%d", 192,168,0,101); //localaddress
		//sprintf(szIPAddress, "%d.%d.%d.%d", 192, 168, 0, 101);

		// Initialize NatNet server with first detected ip address - use NatNet default port assignments
		int retCode = theServer->Initialize(szIPAddress);
		// to use a different port for commands and/or data:
		//int retCode = theServer->Initialize(szIPAddress, CommandPort, DataPort);
		if (retCode != 0) {
			printf("Error initializing server.  See log for details.  Exiting");
			return 1;
		}
		else {
			printf("Server initialized on %s.\n", szIPAddress);
			s.str("");
			s << "Server initialized on " << szIPAddress;
			WriteW(s.str());
		}

		// print address/port info
		char szCommandIP[24];
		char szDataIP[24];
		char szMulticastGroup[24];
		int iDataPort, iCommandPort, iMulticastPort;
		theServer->GetSocketInfo(szDataIP, &iDataPort, szCommandIP, &iCommandPort, szMulticastGroup, &iMulticastPort);
		printf("Command Socket  : %s:%d\n", szCommandIP, iCommandPort);
		s.str("");
		printf("Data Socket     : %s:%d\n", szDataIP, iDataPort);
		s.str("");
		s << "Command Socket : " << szCommandIP << " " << iCommandPort;
		WriteW(s.str());
		s.str("");
		s << "Data Socket : " << szDataIP << " " << iDataPort;
		WriteW(s.str());
		if (iConnectionType == ConnectionType_Multicast) {
			printf("Connection Type : Multicast\n");
			printf("Multicast Group : %s:%d\n", szMulticastGroup, iMulticastPort);
		}
		else {
			//printf("Connection Type : Unicast\n");
			//s.str("");
			//s << "Connection Type : Unicast";
			//WriteW(s.str());
		}
		return ErrorCode_OK;
	}

	/**
	*	Manejador de peticiones, recive peticiones de el cliente.
	*	El servidor deber�a armar y retornar un paquete "respuesta a la petici�n" en el mismo hilo
	*   @param pPacketIn  paquete de datos de el cliente.
	*   @param pPacketOut paquete vac�o, para ser llenado antes de ser retornado al cliente como la "respuesta a la petici�n".
	*/
	int __cdecl RequestHandler(sPacket* pPacketIn, sPacket* pPacketOut, void* pUserData) {
		int iHandled = 1;	// handled

		switch (pPacketIn->iMessage) {
		case NAT_PING:
			printf("[NavarServer] received ping from Client.\n");
			printf("[NavarServer] Client App Name : %s\n", pPacketIn->Data.Sender.szName);
			printf("[NavarServer] Client App Version : %d.%d.%d.%d\n", pPacketIn->Data.Sender.Version[0],
				pPacketIn->Data.Sender.Version[1], pPacketIn->Data.Sender.Version[2], pPacketIn->Data.Sender.Version[3]);
			printf("[NavarServer] Client App NatNet Version : %d.%d.%d.%d\n", pPacketIn->Data.Sender.NatNetVersion[0],
				pPacketIn->Data.Sender.NatNetVersion[1], pPacketIn->Data.Sender.NatNetVersion[2], pPacketIn->Data.Sender.NatNetVersion[3]);

			// build server info packet
			strcpy(pPacketOut->Data.Sender.szName, "NavarServer");
			pPacketOut->Data.Sender.Version[0] = 2;
			pPacketOut->Data.Sender.Version[1] = 1;
			pPacketOut->iMessage = NAT_PINGRESPONSE;
			pPacketOut->nDataBytes = sizeof(sSender);
			iHandled = 1;
			break;

		case NAT_REQUEST_MODELDEF:
			printf("[NavarServer] Received request for data descriptions.\n");
			theServer->PacketizeDataDescriptions(&descriptions, pPacketOut);
			break;

		case NAT_REQUEST_FRAMEOFDATA: {
			// note: Client does not typically poll for data, but we accomodate it here anyway
			// note: need to return response on same thread as caller
			printf("[NavarServer] Received request for frame of data.\n");
			sFrameOfMocapData frame;
			BuildFrame(g_lCurrentFrame, &descriptions, &frame);
			theServer->PacketizeFrameOfMocapData(&frame, pPacketOut);
			FreeFrame(&frame);
		}
									  break;

		case NAT_REQUEST:
			printf("[NavarServer] Received request from Client: %s\n", pPacketIn->Data.szData);
			pPacketOut->iMessage = NAT_UNRECOGNIZED_REQUEST;
			if (stricmp(pPacketIn->Data.szData, "TestRequest") == 0) {
				pPacketOut->iMessage = NAT_RESPONSE;
				strcpy(pPacketOut->Data.szData, "TestResponse");
				pPacketOut->nDataBytes = ((int)strlen(pPacketOut->Data.szData)) + 1;
			}
			break;

		default:
			pPacketOut->iMessage = NAT_UNRECOGNIZED_REQUEST;
			pPacketOut->nDataBytes = 0;
			iHandled = 0;
			break;
		}

		return iHandled; // 0 = not handled, 1 = handled;
	}

	/**
	* Contruye un DataSet que contiene la descripci�n de los objetos r�gidos en escena.
	* Utiliza la descripci�n de los cuerpos r�gidos detectados para ir armando el DataSet.
	* @see CustomCameraLibrary::joskstra()
	* @param pDescription DataSet.
	*/
	void BuildDescription(sDataDescriptions* pDescription) { 
		pDescription->nDataDescriptions = 0;
		int index = 0;
		ofstream archivoD;
		if (!archivoD.is_open()) {
			archivoD.open("test.txt", std::ios::app);

		}
		sResult = WaitForSingleObject(brSemaphore, INFINITE);
		if (sResult == WAIT_OBJECT_0) 
		{
		for (int i = 0; i < nbr; i++) {
			sRigidBodyDescription* pRigidBodyDescription = new sRigidBodyDescription();
			sprintf(pRigidBodyDescription->szName, rigid[i].name.c_str());
			pRigidBodyDescription->ID = i;
			pRigidBodyDescription->parentID = -1;
			pRigidBodyDescription->offsetx = 0.0f;
			pRigidBodyDescription->offsety = 0.0f;
			pRigidBodyDescription->offsetz = 0.0f;
			if (strcmp(pRigidBodyDescription->szName, "POINTER") == 0)
				pRigidBodyDescription->ID = POINTERR;
			else if (strcmp(pRigidBodyDescription->szName, "FEMUR") == 0)
				pRigidBodyDescription->ID = FEMURR;
			else if (strcmp(pRigidBodyDescription->szName, "TIBIA") == 0)
				pRigidBodyDescription->ID = TIBIAA;
			else if (strcmp(pRigidBodyDescription->szName, "GAFAS") == 0)
				pRigidBodyDescription->ID = GAFASS;
			else if (strcmp(pRigidBodyDescription->szName, "BROCA") == 0)
				pRigidBodyDescription->ID = BROCAA;
			//archivoD << pRigidBodyDescription->ID<<"\n"; //testeando que elemento encontro

			pDescription->arrDataDescriptions[index].type = Descriptor_RigidBody;
		
			pDescription->arrDataDescriptions[index].Data.RigidBodyDescription = pRigidBodyDescription;
			pDescription->nDataDescriptions++;
			//archivoD << "dataset" << pDescription->arrDataDescriptions[index].type << "\n";
			//archivoD << "dataset" << pDescription->arrDataDescriptions[index].Data.RigidBodyDescription << "\n";
			index++;
			// Marker Set Description
			sMarkerSetDescription* pMarkerSetDescription = new sMarkerSetDescription();
			sprintf(pMarkerSetDescription->szName, rigid[i].name.c_str());
			pMarkerSetDescription->nMarkers = rigid[i].nmarkers;
			//pMarkerSetDescription->szMarkerNames = new char*[pMarkerSetDescription->nMarkers];
			pMarkerSetDescription->szMarkerNames = new char*[4];
			char szTemp[128];
			for (int j = 0; j < pMarkerSetDescription->nMarkers; j++) {
				sprintf(szTemp, "Marker %d", j);
				pMarkerSetDescription->szMarkerNames[j] = new char[MAX_NAMELENGTH];
				strcpy(pMarkerSetDescription->szMarkerNames[j], szTemp);
			}
			pDescription->arrDataDescriptions[index].type = Descriptor_MarkerSet;
			pDescription->arrDataDescriptions[index].Data.MarkerSetDescription = pMarkerSetDescription;
			pDescription->nDataDescriptions++;
			index++;
			archivoD.close();
		}
		// Release the semaphore when task is finished
		if (!ReleaseSemaphore(sSemaphore, 1, NULL))
			printf("ReleaseSemaphore error: %d\n", GetLastError());
} 

#if STREAM_MARKERS
		// Marker Set Description
		/*		for (int i = 0; i < 3; i++) {
		sMarkerSetDescription* pMarkerSetDescription = new sMarkerSetDescription();
		sprintf(pMarkerSetDescription->szName, "MarkerSet: RigidBody %d", i);
		pMarkerSetDescription->nMarkers = 4;
		pMarkerSetDescription->szMarkerNames = new char*[pMarkerSetDescription->nMarkers];
		char szTemp[128];
		for (int i = 0; i < pMarkerSetDescription->nMarkers; i++) {
		sprintf(szTemp, "Marker %d", i);
		pMarkerSetDescription->szMarkerNames[i] = new char[MAX_NAMELENGTH];
		strcpy(pMarkerSetDescription->szMarkerNames[i], szTemp);
		}
		pDescription->arrDataDescriptions[index].type = Descriptor_MarkerSet;
		pDescription->arrDataDescriptions[index].Data.MarkerSetDescription = pMarkerSetDescription;
		pDescription->nDataDescriptions++;
		index++;
		}
		*/
#endif

#if STREAM_RBS
		// Rigid Body Description
		/*		for (int i = 0; i < 3; i++) {
		sRigidBodyDescription* pRigidBodyDescription = new sRigidBodyDescription();
		sprintf(pRigidBodyDescription->szName, "RigidBody %d", i);
		pRigidBodyDescription->ID = i;
		pRigidBodyDescription->offsetx = 1.0f;
		pRigidBodyDescription->offsety = 2.0f;
		pRigidBodyDescription->offsetz = 3.0f;
		pRigidBodyDescription->parentID = 2;
		pDescription->arrDataDescriptions[index].type = Descriptor_RigidBody;
		pDescription->arrDataDescriptions[index].Data.RigidBodyDescription = pRigidBodyDescription;
		pDescription->nDataDescriptions++;
		index++;
		}
		*/

#endif

#if STREAM_SKELETONS
		// Skeleton description
		for (int i = 0; i < 2; i++)
		{
			sSkeletonDescription* pSkeletonDescription = new sSkeletonDescription();
			sprintf(pSkeletonDescription->szName, "Skeleton %d", i);
			pSkeletonDescription->skeletonID = index * 100;
			pSkeletonDescription->nRigidBodies = 5;
			for (int j = 0; j < pSkeletonDescription->nRigidBodies; j++)
			{
				int RBID = pSkeletonDescription->skeletonID + j;
				sprintf(pSkeletonDescription->RigidBodies[j].szName, "RB%d", RBID);
				pSkeletonDescription->RigidBodies[j].ID = RBID;
				pSkeletonDescription->RigidBodies[j].offsetx = 1.0f;
				pSkeletonDescription->RigidBodies[j].offsety = 2.0f;
				pSkeletonDescription->RigidBodies[j].offsetz = 3.0f;
				pSkeletonDescription->RigidBodies[j].parentID = 2;
			}
			pDescription->arrDataDescriptions[index].type = Descriptor_Skeleton;
			pDescription->arrDataDescriptions[index].Data.SkeletonDescription = pSkeletonDescription;
			pDescription->nDataDescriptions++;
			index++;
		}
#endif
	}

	/**
	* Env�a el DataSet a el cliente.
	* @param pDescription DataSet con la descripci�n de los datos.
	* @see BuildDescription()
	*/
	void SendDescription(sDataDescriptions* pDescription) {
		sPacket packet;
		theServer->PacketizeDataDescriptions(pDescription, &packet);
		theServer->SendPacket(&packet);
	}

	// Release any memory we allocated for our example
	void FreeDescription(sDataDescriptions* pDescription) {
		/*
		for(int i=0; i< pDescription->nDataDescriptions; i++)
		{
		if(pDescription->arrDataDescriptions[i].type == Descriptor_MarkerSet)
		{
		for(int i=0; i< pMarkerSetDescription->nMarkers; i++)
		{
		delete[] pMarkerSetDescription->szMarkerNames[i];
		}
		delete elete[] pMarkerSetDescription->szMarkerNames;
		sMarkerSetDescription* pMarkerSetDescription = pDescription->arrDataDescriptions[0].Data.MarkerSetDescription;
		}
		else if(pDescription->arrDataDescriptions[i].type == Descriptor_RigidBody)
		{
		*/

	}

	// Build frame of MocapData
	/**
	* Construye el frame de datos que ser�n enviados al cliente. Identifica el objeto r�gido que se va a enviar y saca sus propiedades tales como
	* coordenadas 3D de sus esferas, centro del circulo que forman las esferas del cuerpo r�gido, nombre del cuerpo r�gido y orientaci�n.
	* @param FrameNumber contador de frames enviados que indica el frame actual.
	*
	*/
	void BuildFrame(long FrameNumber, sDataDescriptions* pModels, sFrameOfMocapData* pOutFrame) {
		if (!pModels) {
			OutputDebugString(L"NO HAY MODELS");
			printf("No models defined - nothing to send.\n");
			return;
		}

		ZeroMemory(pOutFrame, sizeof(sFrameOfMocapData));
		pOutFrame->iFrame = FrameNumber;
		pOutFrame->fLatency = (float)GetTickCount();
		pOutFrame->nOtherMarkers = 0;
		pOutFrame->nMarkerSets = 0;
		pOutFrame->nRigidBodies = 0;
		pOutFrame->nLabeledMarkers = 0;
		BodyR bdr;

		sResult = WaitForSingleObject(brSemaphore, INFINITE);
		if (sResult == WAIT_OBJECT_0) {
			for (int i = 0; i < pModels->nDataDescriptions; i++) {
				//OutputDebugString(L"Si hay");


				// MarkerSet data
				if (pModels->arrDataDescriptions[i].type == Descriptor_MarkerSet) {
					// add marker data
					int index = pOutFrame->nMarkerSets;
					sMarkerSetDescription* pMS = pModels->arrDataDescriptions[i].Data.MarkerSetDescription;
					strcpy(pOutFrame->MocapData[index].szName, pMS->szName);
					pOutFrame->MocapData[index].nMarkers = pMS->nMarkers;
					pOutFrame->MocapData[index].Markers = new MarkerData[4];

					bdr = getBdrigid(pMS->szName, nbr);		// obtener los marcadores del cuerpo r�gido en cuesti�n
					if (!empty(bdr.bdrigid)) {
						//OutputDebugString(L"Si hay 222");
						for (int iMarker = 0; iMarker < pOutFrame->MocapData[index].nMarkers; iMarker++) {
							double x = (bdr.bdrigid(0, iMarker)) / 1000;
							double y = (bdr.bdrigid(1, iMarker)) / 1000;
							double z = (bdr.bdrigid(2, iMarker)) / 1000;
							//			double rads = (double)counter * 3.14159265358979 / 180.0f;
							pOutFrame->MocapData[index].Markers[iMarker][0] = x;		// x
							pOutFrame->MocapData[index].Markers[iMarker][1] = y;		// y
							pOutFrame->MocapData[index].Markers[iMarker][2] = z;		// z
							counter++;
							counter %= 360;
						}
						pOutFrame->nMarkerSets++;
					}
				}

				// RigidBody data
				if (pModels->arrDataDescriptions[i].type == Descriptor_RigidBody) {
					sRigidBodyDescription* pMS = pModels->arrDataDescriptions[i].Data.RigidBodyDescription;
					bdr = getBdrigid(pMS->szName, nbr);		// obtener los marcadores del cuerpo r�gido en cuesti�n
					if (!empty(bdr.centroid)) {
						int index = pOutFrame->nRigidBodies;
						sRigidBodyData* pRB = &pOutFrame->RigidBodies[index];

						pRB->ID = pMS->ID;
						//					double rads = (double)counter * 3.14159265358979 / 180.0f;
						//					cout << bdr.centroid << endl;
						//						if (empty(bdr.centroid))
						//							system("pause");

						pRB->x = bdr.centroid(0, 0) / 1000;
						pRB->y = bdr.centroid(1, 0) / 1000;
						pRB->z = bdr.centroid(2, 0) / 1000;

						EulerAngles ea;
						ea.x = bdr.pitch;
						ea.y = bdr.yaw;
						ea.z = bdr.roll;
						ea.w = EulOrdZXZr;
						Quat q = Eul_ToQuat(ea);
						pRB->qx = bdr.Quat(0, 0);
						pRB->qy = bdr.Quat(0, 1);
						pRB->qz = bdr.Quat(0, 2);
						pRB->qw = bdr.Quat(0, 3);
						/*pRB->qx = bdr.pitch;
						pRB->qy = bdr.yaw;
						pRB->qz = bdr.roll;*/
						//pRB->qx = bdr.Quat(0, 0);// q.x;
						//pRB->qy = bdr.Quat(0, 1);// q.y;
						//pRB->qz = bdr.Quat(0, 2);// q.z;
						//pRB->qw = bdr.Quat(0, 3);// q.w;
						/*					double m[9];
						double d[4] = { bdr.Quat(0, 0), bdr.Quat(0, 1), bdr.Quat(0, 2), bdr.Quat(0, 3) };
						NATUtils::QaternionToRotationMatrix(d, m);
						for (int i = 0; i < 9; i++) {
						cout << m[i] << endl;
						}*/

						/*if (pRB->ID == POINTERR) {
						pRB->qx = bdr.point.x/1000;
						pRB->qy = bdr.point.y/1000;
						pRB->qz = bdr.point.z/1000;
						pRB->qw = bdr.Quat(0, 3);
						}*/
						pRB->nMarkers = bdr.bdrigid.cols;
						pRB->Markers = new MarkerData[pRB->nMarkers];
						pRB->MarkerIDs = new int[pRB->nMarkers];
						pRB->MarkerSizes = new float[pRB->nMarkers];
						pRB->MeanError = 0.0f;
						for (int iMarker = 0; iMarker < pRB->nMarkers; iMarker++) {
							pRB->Markers[iMarker][0] = bdr.bdrigid(0, 0) / 1000;		// x
							pRB->Markers[iMarker][1] = bdr.bdrigid(1, 0) / 1000;		// y
							pRB->Markers[iMarker][2] = bdr.bdrigid(2, 0) / 1000;		// z
							pRB->MarkerIDs[iMarker] = pRB->nMarkers - iMarker;
							pRB->MarkerSizes[iMarker] = 12.0f;
						}
						pOutFrame->nRigidBodies++;
						counter++;
					}
				}
			}
			// Release the semaphore when task is finished
			if (!ReleaseSemaphore(sSemaphore, 1, NULL))
				printf("ReleaseSemaphore error: %d\n", GetLastError());
		}
		else
			cout << "Pimpinelas prei!" << endl;
	}

	/**
	* Empaqueta y env�a un solo frama con datos a el cliente
	* @param pFrame paquete de datos a enviar.
	*/
	void SendFrame(sFrameOfMocapData* pFrame) {
		sPacket packet;
		theServer->PacketizeFrameOfMocapData(pFrame, &packet);
		theServer->SendPacket(&packet);
	}

	// Release any memory we allocated for this sample
	void FreeFrame(sFrameOfMocapData* pFrame) {
		for (int i = 0; i < pFrame->nMarkerSets; i++) {
			delete[] pFrame->MocapData[i].Markers;
		}

		for (int i = 0; i < pFrame->nOtherMarkers; i++) {
			delete[] pFrame->OtherMarkers;
		}

		for (int i = 0; i < pFrame->nRigidBodies; i++) {
			delete[] pFrame->RigidBodies[i].Markers;
			delete[] pFrame->RigidBodies[i].MarkerIDs;
			delete[] pFrame->RigidBodies[i].MarkerSizes;
		}
	}

	// PlayingThread_Func streams data at ~60hz 
	/**
	* Funci�n que se ejecuta en un hilo distinto al principal.
	*/
	DWORD WINAPI PlayingThread_Func(void * empty) {
		while (1) {
			Mat pic2 = Mat::zeros(800, 600, CV_8UC3);
			sFrameOfMocapData frame;
			BuildDescription(&descriptions);
			BuildFrame(g_lCurrentFrame, &descriptions, &frame);
			SendFrame(&frame);
			FreeFrame(&frame);
			//			printf("Sent Frame %d", g_lCurrentFrame);
			s.str("");
			s << "Sent Frame " << to_string(g_lCurrentFrame);
			putText(pic2, s.str(), cv::Point(50, 450), CV_FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255), 1, 8, false);

			g_lCurrentFrame++;
			imshow("Server", pic + pic2);
			HiResSleep(10);
		}

		return ErrorCode_OK;
	}

	/**
	* Inicia el env�o de datos hacia el cliente. Crea un segundo hilo y los sem�foros correspondientes para garantizar la sincronizaci�n.
	*/
	int StartPlayingThread() {
		SECURITY_ATTRIBUTES security_attribs;
		security_attribs.nLength = sizeof(SECURITY_ATTRIBUTES);
		security_attribs.lpSecurityDescriptor = NULL;
		security_attribs.bInheritHandle = TRUE;
		// crear hilo
		PlayingThread_Handle = CreateThread(&security_attribs, 0, PlayingThread_Func, NULL, 0, &PlayingThread_ID);
		
		if (PlayingThread_Handle == NULL) {
			printf("Error creating play thread.");
			return -1;
		}
		else
		{
			g_bPlaying = true; //Bool que indica si está enviando datos al cliente
			OutputDebugString(L"Si envia");
		}

		// crear sem�foros
		sSemaphore = CreateSemaphore(NULL, 1, 1, L"cServer");
		if (sSemaphore == NULL) {
			printf("CreateSemaphore error: %d\n", GetLastError());
			return -1;
		}
		brSemaphore = CreateSemaphore(NULL, 0, 1, L"cbRigids");
		if (brSemaphore == NULL) {
			printf("CreateSemaphore error: %d\n", GetLastError());
			return -1;
		}

		return ErrorCode_OK;
	}

	/**
	* Detiene el env�o de datos hacia el cliente.Cierra el segundo hilo por donde se env�an los datos y los sem�foros que garantizan la sincronizaci�n.
	*/
	int StopPlayingThread() {
		if (PlayingThread_Handle != NULL) {
			CloseHandle(PlayingThread_Handle);
			CloseHandle(sSemaphore);
			CloseHandle(brSemaphore);
			//TerminateThread(PlayingThread_Handle, 0);
		}

		PlayingThread_Handle = NULL;
		g_bPlaying = false;

		return ErrorCode_OK;
	}

	/**
	* Reinicia el servidor, volviendose a conectar a la misma direcci�n ip.
	*/
	void resetServer() {
		int iSuccess = 0;
		char szIPAddress[128];
		theServer->IPAddress_LongToString(lAddresses[0], szIPAddress);	// use first IP detected

		printf("\nRe-initting Server\n\n");

		iSuccess = theServer->Uninitialize();
		if (iSuccess != 0)
			printf("Error uninitting server.\n");

		iSuccess = theServer->Initialize(szIPAddress);
		if (iSuccess != 0)
			printf("Error re-initting server.\n");
	}

	// MessageHandler receives NatNet error mesages
	void __cdecl MessageHandler(int msgType, char* msg) {
		printf("\n%s\n", msg);
	}

	// higer res sleep than standard.
	int HiResSleep(int msecs) {
		HANDLE hTempEvent = CreateEvent(0, true, FALSE, _T(L"TEMP_EVENT"));
		timeSetEvent(msecs, 1, (LPTIMECALLBACK)hTempEvent, 0, TIME_ONESHOT | TIME_CALLBACK_EVENT_SET);
		WaitForSingleObject(hTempEvent, msecs);
		CloseHandle(hTempEvent);
		return 1;
	}

	/**
	* Inicia el servidor y muetsra una ventana con informaci�n de la conexi�n.
	*/
	int StartServer() {
		int iConnectionType = ConnectionType_Unicast;
		int iResult = CreateServer(iConnectionType);
		if (iResult != ErrorCode_OK) {
			printf("Error initializing server.  See log for details.  Exiting");
			return 1;
		}

		// Create a MarkerSet description
		BuildDescription(&descriptions);
		// OK! Ready to stream data.  Listen for request from clients (RequestHandler())
		printf("\n\nCommands:\nn\tnext frame\ns\tstream frames\nr\treset server\nq\tquit\n\r\tmulticast\nu\tunicast\n\n");
		namedWindow("Server", CV_WINDOW_AUTOSIZE);
		WriteW("");
		WriteW("Commands:");
		WriteW("");
		WriteW("n    next frame");
		WriteW("s    stream frames");
		WriteW("r    reset server");
		WriteW("q    quit");
		WriteW("m    multicast");
		WriteW("u    unicast");


		putText(pic, s.str(), cv::Point(50, 50), CV_FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255), 1, 8, false);
		imshow("Server", pic);
		return 0;
	}

	void WriteW(string s) {
		int y = y0 + i*dy;
		putText(pic, s, cv::Point(50, y), CV_FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255), 1, 8, false);
		i++;
	}

	void StreamFrame() {
		g_lCurrentFrame = 0;
		if (g_bPlaying)
			StopPlayingThread();
		else
			StartPlayingThread();
	}

	/**
	* Encuentra un cuerpo r�gido por su nombre, para luego seleccionar sus marcadores.
	* @param name apuntador al nombre del cuerpo r�gido que se le quieren obtener los marcadores que lo conforman.
	* @param nrig n�mero de cuerpos r�gidos detectados.
	* @return un cuerpo r�gido con todos sus atributos o caracter�sticas.
	*/
	BodyR getBdrigid(char *name, int nrig) {
		string str(name);
		BodyR br;
		for (int i = 0; i < nrig; i++) {
			if (rigid[i].name == str) {
				//				if (rigid[i].name != "") {
				//					rigid[i].centroid.copyTo(centroid);
				//					rigid[i].Quat.copyTo(quat);
				//				}
				return rigid[i];
			}
		}
		return br;  // retornarmos el br anterior
	}
}
namespace CCL = CustomCameraLibrary;
#endif // _SERVER_H_
