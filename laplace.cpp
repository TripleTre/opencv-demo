//
// Created by 赵巍 on 2018/7/24.
//
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "util/sharpen.h"
#define IMAGE "/Users/zhaowei/ClionProjects/openCVDemo/img/kui.jpg"

int main()
{
  cv::Mat image = cv::imread(IMAGE);
  cv::Mat result;

  sharpen(image, result);

  cv::namedWindow("Image");
  cv::imshow("Image", result);

  cv::waitKey(0);

  exit(0);
}
