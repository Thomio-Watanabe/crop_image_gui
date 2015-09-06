#include "CroppedImage.hpp"

using namespace cv;
using namespace std;


CroppedImage::CroppedImage()
{
    cropPercentage = 0.2;
}

CroppedImage::~CroppedImage()
{
}

void CroppedImage::printHelp()
{
    cout << "\n Usage: " << endl;
    cout << " $ ./DisplayImage image.jpg \n" << endl;
}


void CroppedImage::loadImage(char* imageName)
{
    // Load image
    image = imread(imageName, CV_LOAD_IMAGE_COLOR );
    if( !image.data ){
        cout << "\n Could not open or find the image \n" << endl;
    }
}

void CroppedImage::printCroppedImageInfo()
{
    cout << " \n -- Print cropped image information -- " << endl;
    cout << " cropPercentage = " << cropPercentage << endl;
    cout << " image rows = " << image.rows << endl;
    cout << " image cols = " << image.cols << endl;
    cout << " crop at x = " << floor(cropPercentage * image.cols) << endl;
    cout << " crop at y = " << floor(cropPercentage * image.rows) << endl;
    cout << " image lenght = " << floor( (1 - 2 * cropPercentage) * image.cols) << endl;
    cout << " image height = " << floor( (1 - 2 * cropPercentage) * image.rows) << endl;
    cout << endl;
}



void CroppedImage::checkCropPercentage()
{
    // Crop image
    if( cropPercentage <= 0 || cropPercentage >= 0.5){
        cout << "\n cropPercentage must be between 0 and 0.5. \n " << endl;
    }
}


void CroppedImage::cropImage()
{
    // Rect myRect(384,216,1152,648);
    Rect myRect(floor(cropPercentage * image.cols),  // x
                floor(cropPercentage * image.rows), // y
                floor( (1 - 2 * cropPercentage) * image.cols), // lenght
                floor( (1 - 2 * cropPercentage) * image.rows)); // hight
    image = image(myRect);
}


void CroppedImage::displayImage()
{
    // Display cropped image
    namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow("Display window", image);
    waitKey(0);
}

void CroppedImage::saveImage(char* argv )
{
    // Save the image
    string imageName("cropped_");
    imageName.append( argv );
    imwrite( imageName.c_str(), image );
}

//
// int main( int argc, char** argv )
// {
//
//     CroppedImage croppedImage;
//     // Check parsed arguments
//     if( argc != 2 ){
//         croppedImage.printHelp();
//         return -1;
//     }
//     croppedImage.loadImage( argv[1] );
//     croppedImage.printCroppedImageInfo();
//     croppedImage.cropImage();
//     croppedImage.displayImage();
//     croppedImage.saveImage(argv[1]);
//
//     return 0;
// }


