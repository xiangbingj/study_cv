#include<stdio.h>
#include "zq_cv.h"
#include "study_cv.h"

int main(int argc, char* argv[])
{
    ZqImage* img = imread("lena/baby_24.bmp");//读取原始图像(灰度或彩色)
    ZqImage* imgPer = imshear(img, -30, 'x');
    ZqImage* imgPer1 = imshear(img, 30, 'x');
    //输出图像
    imwrite("Result.bmp", img);
    imwrite("perResult0.bmp", imgPer);
    imwrite("perResult1.bmp", imgPer1);
    getchar();
    return 0;
}
