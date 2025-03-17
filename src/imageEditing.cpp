#include "imageEditing.h"

cv::Mat readImage(const std::string& img_path){
    cv::Mat img = cv::imread(img_path, cv::IMREAD_COLOR);
    if(img.empty())
        FatalError( "Could not read the image: " + img_path);
    
    return img;
}

cv::Mat resizeImage(const cv::Mat& img, const int new_w, const int new_h){
    cv::Mat out_img;
    cv::resize(img, out_img, cv::Size(new_w, new_h ));
    return out_img;
}

void showImage(const cv::Mat& img){
    cv::imshow("Image", img);
    cv::waitKey(0);
}

void saveImage(const cv::Mat& img, const std::string& filename){
    if(!img.empty())
        cv::imwrite(filename, img);
}