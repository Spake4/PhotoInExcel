#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "usePythonScript.hpp"
#include <stdio.h>

int main() {
    
    std::string path_to_image = "D:/PhotoInExcel/Image/etterna.png";

    cv::Mat gray_image = cv::imread(path_to_image, cv::IMREAD_GRAYSCALE);

    if (gray_image.empty()) {
        std::cout << "Не удалось загрузить изображение." << std::endl;
        return -1;
    }

    int rows = gray_image.rows;
    int cols = gray_image.cols;

    std::fstream photo;

    photo.open("D:/PhotoInExcel/src/dataFile.txt");

    for (int i = 0; i < rows; ++i) {    
        for (int j = 0; j < cols; ++j) {
            if(static_cast<int>(gray_image.at<uchar>(i, j)) == 255)
                photo << "* ";
            else
                photo << static_cast<int>(gray_image.at<uchar>(i, j)) << ' ';
        }
        photo << "# ";
    }
    photo.close();

    ScriptPython f;

    if(f.useScriptPython()){
        return 1;
    }
    photo.clear();
    return 0;
}
