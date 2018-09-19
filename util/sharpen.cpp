//
// Created by 赵巍 on 2018/7/24.
//

#include <opencv2/core.hpp>

void sharpen(const cv::Mat &image, cv::Mat &result)
{
  result.create(image.size(), image.type());

  int num_channels = image.channels();

  for (int j = 1; j < image.rows - 1; j++) {
    const uchar *previous = image.ptr<const uchar>(j - 1);
    const uchar *current = image.ptr<const uchar>(j);
    const uchar *next = image.ptr<const uchar>(j + 1);

    uchar *output = result.ptr<uchar>(j);

    for (int i = num_channels; i < (image.cols - 1) * num_channels; i++) {
      *output++ = cv::saturate_cast<uchar>(
        5 * current[i] - current[i - num_channels] -
        current[i + num_channels] - previous[i] - next[i]
      );
    }
  }

  const cv::Scalar SCALAR_0 = cv::Scalar(0, 0, 0);

  result.row(0).setTo(SCALAR_0);
  result.row(result.rows - 1).setTo(SCALAR_0);
  result.col(0).setTo(SCALAR_0);
  result.col(result.cols - 1).setTo(SCALAR_0);
}
