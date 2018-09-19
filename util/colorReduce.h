//
// Created by 赵巍 on 2018/7/20.
//
#include <opencv2/core.hpp>

#ifndef OPENCVDEMO_COLORREDUCE_H
#define OPENCVDEMO_COLORREDUCE_H

void colorReduce(cv::Mat& image, int div = 64);
void colorReduce(int div, cv::Mat image);

#endif //OPENCVDEMO_COLORREDUCE_H
