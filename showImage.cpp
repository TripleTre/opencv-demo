//
// Created by 赵巍 on 2018/7/18.
//

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

void mouseHandle(int event, int x, int y, int flags, void* param);

int main() {
  cv::Mat image;

  std::cout << "This image is " << image.rows << " x "
            << image.cols << std::endl;

  image = cv::imread("/Users/zhaowei/Desktop/project/opencv-demo/img/kui.jpg", cv::IMREAD_GRAYSCALE);

  if (image.empty()) {
    std::cout << "image read failed" << std::endl;
    exit(-1);
  }

  cv::namedWindow("Original Image");
  cv::imshow("Original Image", image);

  cv::Mat result;

  cv::flip(image, result, 0);
  cv::namedWindow("Result Image");
  cv::imshow("Result Image", result);

  cv::setMouseCallback("Original Image", mouseHandle, reinterpret_cast<void*>(&image));

  cv::waitKey(0);
  return 0;
}

void mouseHandle(int event, int x, int y, int flags, void* param) {
  cv::Mat* img = reinterpret_cast<cv::Mat*>(param);

  switch (event) {
    case cv::EVENT_LBUTTONDOWN:
      std::cout << "at (" << x << ", " << y << ") values is: "
                << static_cast<int>(img->at<uchar>(cv::Point(x,y))) << std::endl;
  }
}
