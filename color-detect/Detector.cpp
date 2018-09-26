//
// Created by 赵巍 on 2018/9/22.
//

#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv/cv.hpp>
#include "Detector.h"

ColorDetector::ColorDetector(): maxDist(100), targetColor(0, 197, 253) {
}

ColorDetector::~ColorDetector() {
}

int ColorDetector::getDistanceToTargetColor(const cv::Vec3b& color) {
  // 曼哈顿距离
//  return abs(targetColor[0] - color[0]) +
//         abs(targetColor[1] - color[1]) +
//         abs(targetColor[2] - color[2]);
  // 欧几里得距离
  return static_cast<int>(cv::norm<int, 3>(
    cv::Vec3i(
      targetColor[0] - color[0],
      targetColor[1] - color[1],
      targetColor[2] - color[2]
  )));
}

const cv::Mat ColorDetector::process(const cv::Mat& resource) {
  cv::Mat result;
  result.create(resource.size(), CV_8U);
  cv::Mat_<cv::Vec3b>::const_iterator sourceBegin = resource.begin<cv::Vec3b>();
  cv::Mat_<cv::Vec3b>::const_iterator sourceEnd = resource.end<cv::Vec3b>();
  cv::Mat_<uchar>::iterator resultBegin = result.begin<uchar>();

  for (; sourceBegin != sourceEnd; sourceBegin++, resultBegin++) {
    if (getDistanceToTargetColor(*sourceBegin) <= maxDist) {
      *resultBegin = 255;
    } else {
      *resultBegin = 0;
    }
  }

  return result;
}


