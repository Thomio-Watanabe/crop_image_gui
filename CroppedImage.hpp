#ifndef _CROPPED_IMAGE_HPP_
#define _CROPPED_IMAGE_HPP_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
//#include <cmath>

class CroppedImage{
    private:
        float cropPercentage;
        cv::Mat image;
        std::string inameName;
    public:
        CroppedImage();
        ~CroppedImage();

        void printHelp();
        void printCroppedImageInfo();
        void loadImage(char *imageName);
        void checkCropPercentage();
        void cropImage();
        void displayImage();
        void saveImage(char *imageName);
};

#endif
