//nose me aburria y he hecho esto y me estoy despollando con una foto de un mono entiendanme
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <math.h>
#include <iostream>
using namespace std;

int main(int argc,char ** argv){
	cv::Mat input,output;
	uchar inversa[256];
	uchar j=0;
	vector<cv::Mat> ogs(3);
    vector<cv::Mat> outs(3);

	input=cv::imread(argv[1]);

	if(input.rows==0){

		cout<<"ERROR:Failed to open the image"<<endl;

		return 0;
	}
	
	for (int i=255;i>=0;i--){
		inversa[i]=j;
		j++;
	}
	input.convertTo(input,CV_8UC3);
	output.create(input.size(),input.type());
	cv::split(input,ogs);
	cv::split(output,outs);


for(int m=0;m<3;m++){

	for(int y=0;y<input.rows;y++){
		for(int x=0;x<output.cols;x++){
 
			outs[m].at<uchar>(cv::Point(x,y))= inversa[ogs[m].at<uchar>(cv::Point(x,y))];

		}
	}
}
	cv::merge(outs,output);

	cv::imwrite(argv[1],output);

	cv::waitKey(0);

}