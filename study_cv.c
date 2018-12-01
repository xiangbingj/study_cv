#include "study_cv.h"
#include <stdlib.h>

unsigned char mid_val(unsigned char *a, int num)
{
    unsigned char temp;
    int i = 0;
    for (i = 0; i < num; i++)
    {
        temp = a[i];
        int j = i;
        for (; j > 0 && a[j - 1] > temp; j--)
            a[j] = a[j - 1];
        a[j] = temp;
    }

    return a[num/2];
}

int study_is_in_array(short x, short y, short height, short width)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
        return 1;
    else
        return 0;
}

ZqImage* study_filtering(ZqImage* bmpImg)
{
    //图片平滑线性滤波处理
    ZqImage* bmpImgFilter;
    int width = 0;
    int height = 0;
    int step = 0;
    int filter_step = 0;
    int channels = 1;
    int i, j, k;
    width = bmpImg->width;
    height = bmpImg->height;
    channels = bmpImg->channels;

    //初始化处理后图片的信息
    bmpImgFilter = (ZqImage*)malloc(sizeof(ZqImage));
    bmpImgFilter->channels = channels;
    bmpImgFilter->width = width;
    bmpImgFilter->height = height;

    step = channels * width;
    filter_step = bmpImgFilter->channels * bmpImgFilter->width;
    bmpImgFilter->imageData = (unsigned char*)malloc(sizeof(unsigned char)*bmpImgFilter->width*bmpImgFilter->height*bmpImgFilter->channels);

    unsigned char average[3][3] =
    {
        {1, 2, 1},
        {2, 4, 2},
        {1, 2, 1}
    };
    //初始化图像
    for (i=0; i<bmpImgFilter->height; i++)
    {
        for (j=0; j<bmpImgFilter->width; j++)
        {
            bmpImgFilter->imageData[(bmpImgFilter->height-1-i)*filter_step+j] = 0;
        }
    }

    /* linear filtering */
     short sum = 0;
     for (i = 0; i < 3; i++)
         for (j = 0; j < 3; j++)
             sum += average[i][j];

    //滤波处理
    unsigned char value[9];
    for(i = 0;i < bmpImgFilter->height;i++)
    {
        for(j = 0;j < bmpImgFilter->width;j++)
        {
            for(k=0; k<channels; k++)
            {
            value[0] = study_is_in_array(j-1, i-1, height, width) ? bmpImg->imageData[(i-1) * step + (j-1)*channels + k] : 0;
            value[1] = study_is_in_array(j, i-1, height, width) ? bmpImg->imageData[(i-1) * step + j*channels + k] : 0;
            value[2] = study_is_in_array(j+1, i-1, height, width) ? bmpImg->imageData[(i-1) * step + (j+1)*channels + k] : 0;
            value[3] = study_is_in_array(j-1, i, height, width) ? bmpImg->imageData[i * step + (j-1)*channels + k] : 0;
            value[4] = bmpImg->imageData[i * step + j*channels + k];
            value[5] = study_is_in_array(j+1, i, height, width) ? bmpImg->imageData[i * step + (j+1)*channels + k] : 0;
            value[6] = study_is_in_array(j-1, i+1, height, width) ? bmpImg->imageData[(i+1) * step + (j-1)*channels + k] : 0;
            value[7] = study_is_in_array(j, i+1, height, width) ? bmpImg->imageData[(i+1) * step + j*channels + k] : 0;
            value[8] = study_is_in_array(j+1, i+1, height, width) ? bmpImg->imageData[(i+1) * step + (j+1)*channels + k] : 0;

            /* linear filtering */
             bmpImgFilter->imageData[i * filter_step + j*channels +k] = (value[0] * average[0][0] + value[1] * average[0][1] + 
                                value[2] * average[0][2] + value[3] * average[1][0] + value[4] * average[1][1] + 
                                value[5] * average[1][2] + value[6] * average[2][0] + value[7] * average[2][1] + value[8] * average[2][2]) / sum;
            /* median filtering */
            bmpImgFilter->imageData[i * filter_step + j*channels +k] = mid_val(value, 9);
            }
        }
    }

    return bmpImgFilter;
}

ZqImage* study_imgamma(ZqImage* bmpImg)
{
    //灰度图片gamma处理
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
            unsigned char color = bmpImg->imageData[i * step + j*channels];
            float c = (float)color / 0xff;

            bmpImgGray->imageData[i * gray_step + j] = pow(c, 2.2)*0xff;
            ;
        }
    }

    return bmpImgGray;
}

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
