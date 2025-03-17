#include<iostream>
#include "utils.h"
#include "Specs.h"
#include "imageEditing.h"

int main(int argc, char* argv[]){
    // 1. Accept two arguments
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <image_path> <spec_path>" << std::endl;
        return 1;
    }

    std::cout<<"This is the demo, using ";
    printOpenCVVersion();

    // 2. Parse the spec file
    std::filesystem::path filepath = argv[2];
    Specs mySpecs;
    mySpecs.parseFromFile(filepath);

    // 3. Load the image
    cv::Mat img = readImage(argv[1]);

    // 4. Resize the image
    cv::Mat resized_img = resizeImage(img, mySpecs.getAvgWidth(), mySpecs.getAvgHeight());

    // 5. Show and save the image
    showImage(resized_img);
    std::filesystem::path image_path = argv[1];
    std::filesystem::path image_dir = image_path.parent_path().string();
    std::string image_name = image_path.filename().string();
    saveImage(resized_img, image_dir / ("resized_" + image_name));

    return 0;
}