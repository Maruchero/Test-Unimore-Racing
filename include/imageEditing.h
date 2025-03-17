#ifndef IMAGEEDITING_H
#define IMAGEEDITING_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "utils.h"

cv::Mat readImage(const std::string& img_path);
cv::Mat resizeImage(const cv::Mat& img, const int new_w, const int new_h);
void showImage(const cv::Mat& img);
void saveImage(const cv::Mat& img, const std::string& filename);

#endif /*IMAGEEDITING_H*/