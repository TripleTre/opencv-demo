//
// Created by 赵巍 on 2018/7/20.
//
#include <opencv2/core.hpp>
#include <iostream>
#include "colorReduce.h"

void colorReduce(cv::Mat& image, int div) {
  int rows = image.rows;
  if (image.step == image.cols * image.elemSize()) {
    std::cout << "wtf" << std::endl;
  }
  int nc = image.cols * image.channels();

  for (int j = 0; j < rows; j++) {
    uchar* data = image.ptr<uchar>(j);

    for (int i = 0; i < nc; i++) {
      data[i] = data[i] / div * div + div / 2;
    }
  }
}

void colorReduce(int div, cv::Mat image) {
  int n = static_cast<int>(log(static_cast<double>(div))/log(2.0) + 0.5);

  uchar mask = 0xFF << n;
  uchar div2 = div >> 1;
  cv::MatIterator_<cv::Vec3b> begin = image.begin<cv::Vec3b>();
  cv::MatIterator_<cv::Vec3b> end = image.end<cv::Vec3b>();

  for ( ; begin != end; begin++) {
    (*begin)[0] &= mask;
//    (*begin)[0] += div2;
    (*begin)[1] &= mask;
//    (*begin)[1] += div2;
    (*begin)[2] &= mask;
//    (*begin)[2] += div2;
  }
}
