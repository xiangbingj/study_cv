#include<stdio.h>
#include "zq_cv.h"
#include "study_cv.h"

int main(int argc, char* argv[])
{
    ZqImage* img = imread("lena/baby_24.bmp");//读取原始图像(灰度或彩色)
    ZqImage* imgPer = study_PerspectiveTransform(img);

    //输出图像
    imwrite("Result.bmp", img);
    imwrite("perResult.bmp", imgPer);
    getchar();
    return 0;
}
