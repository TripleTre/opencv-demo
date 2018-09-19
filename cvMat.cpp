//
// Created by 赵巍 on 2018/7/18.
//

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#define IMAGE "/Users/zhaowei/ClionProjects/openCVDemo/img/kui.jpg"

using namespace cv;

Mat function() {
  Mat ima(500, 500, CV_8U, 10);
  return ima;
}

int main() {

  Mat image1(240, 320, CV_8U, 100);
  imshow("Image", image1);
  waitKey(0);

  image1.create(200, 200, CV_8UC3);
  image1 = Scalar(255, 0, 255);

  imshow("Image", image1);
  waitKey(0);

  // 红色图像，通道次序为 BGR
  Mat image2(240, 320, CV_8UC3, Scalar(0, 0, 255));

  // Mat image2(Size(320, 240), CV_8UC3);
  // image2= Scalar(0, 0, 255);

  imshow("Image", image2);
  waitKey(0);

  Mat image3 = imread(IMAGE);

  Mat image4(image3);
  image1 = image3;

  image3.copyTo(image2);
  Mat image5 = image3.clone();

  flip(image3, image3, 1);

  imshow("Image 3", image3);
  imshow("Image 1", image1);
  imshow("Image 2", image2);
  imshow("Image 4", image4);
  imshow("Image 5", image5);

  waitKey(0);

  Mat gray = function();
  imshow("Image", gray);
  waitKey(0);

  image1 = imread(IMAGE, CV_LOAD_IMAGE_GRAYSCALE);
  image1.convertTo(image2, CV_32F, 1/255.0, 0.0);

  imshow("Image", image2);
  waitKey(0);

  return 0;
}
