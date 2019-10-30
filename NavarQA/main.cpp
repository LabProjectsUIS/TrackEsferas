#include "NavarQT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NavarQT w;
	w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	w.setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

	w.showFullScreen();
	return a.exec();
}
