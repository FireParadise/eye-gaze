#include <math.h>
#include <stdlib.h>
#include <string>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/legacy/compat.hpp>

using namespace std;

void kmeans_array_generate(cv::Mat src, std::vector<std::vector<double> >& vec, int mode) {
	if(vec.size() != 0) {
		vec.clear();
	}

	int rows = src.rows;
	int cols = src.cols;

	vec.resize(cols*rows);

	int idx = 0;

	cv::Mat src_hsv;
	cv::cvtColor(src, src_hsv, CV_RGB2HSV);

	std::vector<cv::Mat> hsv;
	cv::split(src, hsv);

	for(int i=0;i<rows;i++) {
		for(int j=0;j<cols;j++) {
			//vec[idx].push_back(((double) j)/cols);
			//vec[idx].push_back(((double) i)/rows);
			//std::cout<<"hue : "<<((double)(hsv[0].at<uchar>(j,i)))<<std::endl;
			vec[idx].push_back(((double) hsv[0].at<uchar>(j, i)));

			idx++;
		}
	}
}

void kmeans_clusters_view(cv::Mat& src, std::vector<int> vec_labels) {
	int rows = src.rows;
	int cols = src.cols;

	int idx = 0;
	std::cout<<vec_labels.size()<<"\t"<<rows;
	/*for(int i=0;i<rows;i++) {
		for(int j=0;j<cols;j++) {
			int clr = vec_labels[idx]*100 + 50;

			src.at<cv::Vec3b>(j, i)[0] = clr;
			src.at<cv::Vec3b>(j, i)[1] = clr;
			src.at<cv::Vec3b>(j, i)[2] = clr;

			idx++;
		}
	}*/
}