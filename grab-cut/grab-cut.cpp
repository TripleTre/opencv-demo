//
// Created by 赵巍 on 2018/9/26.
//
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main()
{
  cv::Mat source = cv::imread("/Users/zhaowei/Desktop/project/opencv-demo/img/timg.jpeg", cv::IMREAD_COLOR);

  std::cout << source.type() << std::endl;

  cv::Mat result;
  cv::Mat bgModel, fgModel;
  cv::Rect rect(288, 189, 131, 126);
  cv::grabCut(
    source,
    result,
    rect,
    bgModel, fgModel,
    5,
    cv::GC_INIT_WITH_RECT);
  // mask 中留下可能是前景的像素
  cv::compare(result, cv::GC_PR_FGD, result, cv::CMP_EQ);

  cv::Mat foreground(source.size(), CV_8UC3, cv::Scalar(255, 255, 255));
  source.copyTo(foreground, result);

  cv::namedWindow("grab-cut");
  cv::imshow("grab-cut", foreground);

  cv::waitKey(0);
}
