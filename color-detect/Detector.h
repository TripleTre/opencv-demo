//
// Created by 赵巍 on 2018/9/22.
//

#ifndef OPENCVDEMO_DETECTOR_H
#define OPENCVDEMO_DETECTOR_H

#include <opencv2/core/matx.hpp>

class ColorDetector {
  private:
    const int maxDist;
    const cv::Vec3b targetColor;

    int getDistanceToTargetColor(const cv::Vec3b&);

  public:
    ColorDetector();
    ~ColorDetector();

    const cv::Mat process(const cv::Mat&);
};

#endif //OPENCVDEMO_DETECTOR_H
