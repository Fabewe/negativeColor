
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

	input=cv::imread(argv[1],cv::IMREAD_GRAYSCALE);

	if(input.rows==0){

		cout<<"ERROR:Failed to open the image"<<endl;

		return 0;
	}
	
	for (int i=255;i>=0;i--){
		inversa[i]=j;
		j++;
	}

	output.create(input.size(),input.type());



	for(int y=0;y<input.rows;y++){
		for(int x=0;x<output.cols;x++){
 
			output.at<uchar>(cv::Point(x,y))= inversa[input.at<uchar>(cv::Point(x,y))];

		}
	}

	cv::imwrite(argv[1],output);

	cv::waitKey(0);

}