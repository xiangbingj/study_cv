#include<stdio.h>
#include "zq_cv.h"
#include "study_cv.h"

int main(int argc, char* argv[])
{
    ZqImage* img = imread("lena/SaltResult.bmp");//读取原始图像(灰度或彩色)
    ZqImage* imgFilter = study_filtering(img);

    //输出图像
    imwrite("Result.bmp", img);
    imwrite("SaltResult.bmp", imgFilter);
    getchar();
    return 0;
}
