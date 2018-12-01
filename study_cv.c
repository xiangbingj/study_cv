#include "study_cv.h"
#include <stdlib.h>

ZqImage* study_bpp24_to_grayscale(ZqImage* bmpImg)
{
    //图片24bit转灰度处理
    ZqImage* bmpImgGray;
    int width = 0;
    int height = 0;
    int step = 0;
    int gray_step = 0;
    int channels = 1;
    int i, j;
    width = bmpImg->width;
    height = bmpImg->height;
    channels = bmpImg->channels;

    //初始化处理后图片的信息
    bmpImgGray = (ZqImage*)malloc(sizeof(ZqImage));
    bmpImgGray->channels = 1;
    bmpImgGray->width = width;
    bmpImgGray->height = height;

    step = channels * width;
    gray_step = bmpImgGray->channels * bmpImgGray->width;
    bmpImgGray->imageData = (unsigned char*)malloc(sizeof(unsigned char)*bmpImgGray->width*bmpImgGray->height*bmpImgGray->channels);

    //初始化灰度图图像
    for (i=0; i<bmpImgGray->height; i++)
    {
        for (j=0; j<bmpImgGray->width; j++)
        {
            bmpImgGray->imageData[(bmpImgGray->height-1-i)*gray_step+j] = 0;
        }
    }
    //坐标变换
    for(i = 0;i < bmpImgGray->height;i++)
    {
        for(j = 0;j < bmpImgGray->width;j++)
        {
            unsigned char red = bmpImg->imageData[i * step + j*channels];
            unsigned char green = bmpImg->imageData[i * step + j*channels +1];
            unsigned char blue = bmpImg->imageData[i * step + j*channels + 2];
            
            bmpImgGray->imageData[i * gray_step + j] = (red + green + blue) / 3;
        }
    }

    return bmpImgGray;
}
