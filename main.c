#include<stdio.h>
#include "zq_cv.h"

int main(int argc, char* argv[])
{
    ZqImage* img = imread("lena/lena.bmp");//读取原始图像(灰度或彩色)
    ZqImage* imgRot = imrotate(img,73);//旋转原始图像73°
    ZqImage* imgSca = imscale(img,0.5,1.3);//缩放图像宽0.5倍，高1.3倍
    //输出图像
    imwrite("Result.bmp", img);
    imwrite("RotResult.bmp", imgRot);
    imwrite("ScaResult.bmp", imgSca);
    getchar();
    return 0;
}
