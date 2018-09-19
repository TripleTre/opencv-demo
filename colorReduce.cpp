//
// Created by 赵巍 on 2018/7/20.
//
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "util/colorReduce.h"
#define IMAGE "/Users/zhaowei/ClionProjects/openCVDemo/img/kui.jpg"

int main() {
  cv::Mat image = cv::imread(IMAGE);

  colorReduce(128, image);

  cv::namedWindow("Image");
  cv::imshow("Image", image);

  cv::waitKey(0);
}
