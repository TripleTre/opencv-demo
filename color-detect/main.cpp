//
// Created by 赵巍 on 2018/9/22.
//

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "Detector.h"

int main() {
  ColorDetector detc;
  cv::Mat source = cv::imread("/Users/zhaowei/Desktop/project/opencv-demo/img/kui.jpg", cv::IMREAD_COLOR);
  cv::Mat result;
  result = detc.process(source);

  cv::namedWindow("Original Image");
  cv::imshow("Original Image", result);

  cv::waitKey(0);
}
