//
// Created by 赵巍 on 2018/7/24.
//

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#define IMAGE_A "/Users/zhaowei/ClionProjects/openCVDemo/img/op_a.png"
#define IMAGE_B "/Users/zhaowei/ClionProjects/openCVDemo/img/op_b.png"

int main()
{
  cv::Mat imageA = cv::imread(IMAGE_A);
  cv::Mat imageB = cv::imread(IMAGE_B);

//  imageB.create(imageA.size(), imageA.type());

  cv::Mat result;

  cv::bitwise_not(imageA, imageB, result);

  cv::imshow("Image", result);

  cv::waitKeyEx(0);
}
