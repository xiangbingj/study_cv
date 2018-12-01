#include<stdio.h>
#include "zq_cv.h"
#include "study_cv.h"

int main(int argc, char* argv[])
{
    ZqImage* img = imread("lena/lena.bmp");//读取原始图像(灰度或彩色)
    ZqImage* imgGray = study_bpp24_to_grayscale(img);//旋转原始图像73°

    //输出图像
    imwrite("Result.bmp", img);
    imwrite("GrayResult.bmp", imgGray);
    getchar();
    return 0;
}
