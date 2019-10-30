// icp.cpp : Defines the entry point for the console application.

/*-------------------------------------------------------
Interfaz 2016, all rights reserved.

This code defines a set of functions to align rigid objects.
Both objects, from now on referred as source and target,
are Point Clouds.

Registration is performed in two steps. First, the
source is brought near the target in a process involving
voxelization and a feature-based RANSAC; prior to
features estimation, normals are to be computed. Second,
an ICP algorithm is applied to source in order to match
it to target.

Point clouds can be read from text files using read_file.

Author: Jesús Muñoz
Version: 0.1
---------------------------------------------------------*/

#include <iostream>
#include <sstream>
#include <Eigen/Core>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/common/time.h>
#include <pcl/console/print.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/filters/filter.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/registration/icp_nl.h>
#include <pcl/registration/sample_consensus_prerejective.h>
#include <pcl/visualization/cloud_viewer.h>

#include "opencv\cv.hpp"


// Types
typedef pcl::PointNormal PointNT;
typedef pcl::PointCloud<PointNT> PointCloudT;
typedef pcl::FPFHSignature33 FeatureT;
typedef pcl::FPFHEstimation<PointNT, PointNT, FeatureT> FeatureEstimationT;
typedef pcl::PointCloud<FeatureT> FeatureCloudT;
typedef pcl::RadiusOutlierRemoval<PointNT> RadiusOutlierRemovalT;
typedef pcl::VoxelGrid<PointNT> VoxelGridT;
typedef pcl::NormalEstimation<PointNT, PointNT> NormalEstimationT;
typedef pcl::search::KdTree<PointNT> KdTreeT;
typedef pcl::SampleConsensusPrerejective<PointNT, PointNT, FeatureT> SampleConsensusPrerejectiveT;

/**
* Carga datos en bruto a una nube de puntos desde un archivo de texto sin un formato específico.
* @param file nombre del archivo.
* @param numel número de elementos.
* @out cloud nube de puntos
*/
void read_file(const std::string& file, int numel, PointCloudT::Ptr cloud) {
	cloud->width = numel;
	cloud->height = 1;
	cloud->is_dense = true;
	cloud->points.resize(cloud->width * cloud->height);

	std::ifstream readFile(file);

	// Load data
	for (size_t i = 0; i < cloud->points.size(); ++i)
	{
		std::string line;
		std::string var1, var2, var3;

		getline(readFile, line);
		std::istringstream ss(line);
		ss >> var1 >> var2 >> var3;
		cloud->points[i].x = stof(var1);
		cloud->points[i].y = stof(var2);
		cloud->points[i].z = stof(var3);
	}
};

/**
* Acerca un primer cuerpo rígido a un segundo.
* @param object objeto rígido a acercar.
* @param scene objeto de referencia.
* @out transformation matriz de transformación.
*/
void bring_cloud_near(PointCloudT::Ptr object, PointCloudT::Ptr scene, Eigen::Matrix4f& transformation, int flag) {

	FeatureCloudT::Ptr object_features(new FeatureCloudT);
	FeatureCloudT::Ptr scene_features(new FeatureCloudT);
	PointCloudT::Ptr object_aligned(new PointCloudT);
	RadiusOutlierRemovalT outlierRemoval;
	NormalEstimationT nest;
	VoxelGridT grid;
	KdTreeT::Ptr kdtree(new pcl::search::KdTree<PointNT>);

	const float leaf = 10;
	double radius = 10;

	switch (flag) {
	case 1:
		// Remove outliers
		outlierRemoval.setInputCloud(object);
		// Every point must have 10 neigbors within 10mm, or it will be removed.
		outlierRemoval.setRadiusSearch(10);
		outlierRemoval.setMinNeighborsInRadius(10);
		outlierRemoval.filter(*object);
		radius = 5;
		nest.setSearchMethod(kdtree);
		break;
	case 2:
		// Downsample
		grid.setLeafSize(leaf, leaf, leaf);
		grid.setInputCloud(object);
		grid.filter(*object);
		grid.setInputCloud(scene);
		grid.filter(*scene);
		radius = 0.1;
		break;
	default:
		break;
	}

	// Estimate normals for scene
	nest.setRadiusSearch(radius);
	nest.setInputCloud(scene);
	nest.compute(*scene);

	// Estimate features
	FeatureEstimationT fest;
	fest.setRadiusSearch(50);
	fest.setInputCloud(object);
	fest.setInputNormals(object);
	fest.compute(*object_features);
	fest.setInputCloud(scene);
	fest.setInputNormals(scene);
	fest.compute(*scene_features);

	// Perform alignment
	SampleConsensusPrerejectiveT align;
	align.setInputSource(object);
	align.setSourceFeatures(object_features);
	align.setInputTarget(scene);
	align.setTargetFeatures(scene_features);
	align.setMaximumIterations(50000); // Number of RANSAC iterations
	align.setNumberOfSamples(10); // Number of points to sample for generating/prerejecting a pose
	align.setCorrespondenceRandomness(10); // Number of nearest features to use
	align.setSimilarityThreshold(0.0001f); // Polygonal edge length similarity threshold
	align.setMaxCorrespondenceDistance(1.01f * leaf); // Inlier threshold
	align.setInlierFraction(0.95f); // Required inlier fraction for accepting a pose hypothesis
	{
		pcl::ScopeTime t("Alignment");
		align.align(*object_aligned);
	}


	if (align.hasConverged())
	{
		pcl::transformPointCloud(*object, *object, align.getFinalTransformation());
		transformation = align.getFinalTransformation().inverse();
	}
	else
	{
		pcl::console::print_error("Alignment failed!\n");
	}
}

/**
* Alinea un objeto rígido a una escena utilizando una variante del algoritmo ICP
* @param object objeto rígido.
* @param scene escena.
* @out transformation matriz de transformación.
*/
void do_icp(PointCloudT::Ptr object, PointCloudT::Ptr scene, Eigen::Matrix4f& transformation) {
	pcl::IterativeClosestPointNonLinear<PointNT, PointNT> icp;
	icp.setInputCloud(object);
	icp.setInputTarget(scene);
	icp.align(*object);
	transformation = icp.getFinalTransformation().inverse();
}

/**
* Acerca una nube de puntos lejana a otra de referencia.
* @param source_file archivo nube 1 (a acercar).
* @param target_file archivo nube 2 (de referencia).
* @param numel_source número de elementos de la nube 1.
* @param numel_target número de elementos de la nube 2.
*/
void run_icp(const std::string& source_file, const std::string& target_file, int numel_source, int numel_target, cv::Mat_<double>& cloud_centroid)
{
	// Point clouds
	PointCloudT::Ptr temp(new PointCloudT);
	PointCloudT::Ptr temp2(new PointCloudT);
	PointCloudT::Ptr object(new PointCloudT);
	PointCloudT::Ptr scene(new PointCloudT);
	PointCloudT::Ptr source(new PointCloudT);
	PointCloudT::Ptr target(new PointCloudT);
	Eigen::Matrix4f transformation_n;
	Eigen::Matrix4f transformation_icp;
	int flag;

	read_file(source_file, numel_source, source);
	read_file(target_file, numel_target, target);

	pcl::copyPointCloud(*source, *object);
	pcl::copyPointCloud(*target, *scene);
	switch (numel_target) {
	case 32986:
		flag = 2;
		break;
	case 23974:
		flag = 2;//
		break;
	default:
		flag = 1;
		break;
	}
	bring_cloud_near(object, scene, transformation_n, flag);
	do_icp(object, scene, transformation_icp);

	pcl::transformPointCloud(*target, *target, transformation_icp);
	pcl::transformPointCloud(*target, *target, transformation_n);
	Eigen::Matrix4f transformation = transformation_n * transformation_icp;

	boost::shared_ptr< pcl::visualization::PCLVisualizer > viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));
	viewer->setBackgroundColor(0, 0, 0);

	// white
	pcl::visualization::PointCloudColorHandlerCustom<PointNT> target_color(target, 255, 255, 255);
	viewer->addPointCloud<PointNT>(target, target_color, "target");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "target");

	// red
	pcl::visualization::PointCloudColorHandlerCustom<PointNT> source_color(source, 255, 0, 0);
	viewer->addPointCloud<PointNT>(source, source_color, "source");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "source");

	viewer->resetCamera();

	//while (!viewer->wasStopped())
	//{
	//	viewer->spinOnce();
	//	boost::this_thread::sleep(boost::posix_time::microseconds(100000));
	//}

	//return (0);
	cloud_centroid = (cv::Mat_<double>(3, 1) << transformation(0, 3), transformation(1, 3), transformation(2, 3));

	//return viewer;
}