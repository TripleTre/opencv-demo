//
// Created by 赵巍 on 2018/9/19.
//

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main() {
  cv::Mat source = cv::imread("/Users/zhaowei/Desktop/project/opencv-demo/img/foo.jpeg", cv::IMREAD_COLOR);

  cv::Mat srcX(source.rows, source.cols, CV_32F);
  cv::Mat srcY(source.rows, source.cols, CV_32F);
  cv::Mat result;

  const int64 start = cv::getTickCount();

  for (int i = 0; i < source.rows; i++) {
    for (int j = 0; j < source.cols; j++) {
      srcX.at<float>(i, j) = source.cols - j - 1;
      srcY.at<float>(i, j) = i;
    }
  }

  double duration = (cv::getTickCount() - start) / cv::getTickFrequency();

  std::cout << duration << std::endl;

  cv::remap(source, result, srcX, srcY, cv::INTER_LINEAR);

  std::cout << srcX.at<float>(0, 1);

  cv::namedWindow("Original Image");
  cv::imshow("Original Image", result);

  cv::waitKey(0);
}
