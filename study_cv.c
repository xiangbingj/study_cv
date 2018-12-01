#include "study_cv.h"
#include <stdlib.h>

double study_gaussrand()
{
    static double V1, V2, S;
    static int phase = 0;
    double X;

    if(phase == 0) {
        do
        {
            double U1 = (double)rand() / RAND_MAX;
            double U2 = (double)rand() / RAND_MAX;

            V1 = 2 * U1 - 1;
            V2 = 2 * U2 - 1;
            S = V1 * V1 + V2 * V2;
        } while(S >= 1 || S == 0);

        X = V1 * sqrt(-2 * log(S) / S);
    }
    else
        X = V2 * sqrt(-2 * log(S) / S);

    phase = 1 - phase;

    return X * 50;
}

ZqImage *study_add_gaussian_noise(ZqImage* bmpImg)
{
    //生成高斯噪声
    ZqImage* bmpImgGaussian;
    int width = 0;
    int height = 0;
    int step = 0;
    int gaussian_step = 0;
    int channels = 1;
    int i, j, k;
    width = bmpImg->width;
    height = bmpImg->height;
    channels = bmpImg->channels;

    //初始化处理后图片的信息
    bmpImgGaussian = (ZqImage*)malloc(sizeof(ZqImage));
    bmpImgGaussian->channels = channels;
    bmpImgGaussian->width = width;
    bmpImgGaussian->height = height;

    step = channels * width;
    gaussian_step = bmpImgGaussian->channels * bmpImgGaussian->width;
    bmpImgGaussian->imageData =
        (unsigned char*)malloc(sizeof(unsigned char)*bmpImgGaussian->width*bmpImgGaussian->height*bmpImgGaussian->channels);

    //初始化图像
    for (i=0; i<bmpImgGaussian->height; i++)
    {
        for (j=0; j<bmpImgGaussian->width; j++)
        {
            bmpImgGaussian->imageData[(bmpImgGaussian->height-1-i)*gaussian_step+j] = 0;
        }
    }
    //滤波处理
    short value;
    for(i = 0;i < bmpImgGaussian->height;i++)
    {
        for(j = 0;j < bmpImgGaussian->width;j++)
        {
            for(k=0; k<channels; k++)
            {
                value = (short)study_gaussrand() + bmpImg->imageData[i * step + j*channels + k];
                if (value > 0xff)
                    bmpImgGaussian->imageData[i * gaussian_step + j*channels +k] = 0xff;
                else if (value < 0)
                    bmpImgGaussian->imageData[i * gaussian_step + j*channels +k] = 0;
                else
                    bmpImgGaussian->imageData[i * gaussian_step + j*channels +k] = (unsigned char)value;
            }
        }
    }

    return bmpImgGaussian;
}

/*太慢了 = =*/
ZqImage *study_fre_spectrum(ZqImage* bmpImg)
{
    //图片f傅里叶处理
    ZqImage* bmpImgFre;
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
    bmpImgFre = (ZqImage*)malloc(sizeof(ZqImage));
    bmpImgFre->channels = channels;
    bmpImgFre->width = width;
    bmpImgFre->height = height;

    step = channels * width;
    filter_step = bmpImgFre->channels * bmpImgFre->width;
    bmpImgFre->imageData = (unsigned char*)malloc(sizeof(unsigned char)*bmpImgFre->width*bmpImgFre->height*bmpImgFre->channels);

    //初始化图像
    for (i=0; i<bmpImgFre->height; i++)
    {
        for (j=0; j<bmpImgFre->width; j++)
        {
            bmpImgFre->imageData[(bmpImgFre->height-1-i)*filter_step+j] = 0;
        }
    }

    double re, im, temp;
    int move;
    int x, y;
    //滤波处理
    unsigned short value;
    for(i = 0;i < bmpImgFre->height;i++)
    {
        for(j = 0;j < bmpImgFre->width;j++)
        {
            for(k=0; k<channels; k++)
            {
                re = 0;
                im = 0;
                for (x = 0; x < height; x++)
                {
                    for (y = 0; y < width; y++){
                        temp = (double)i * x / (double)height + 
                               (double)j * y / (double)width;
                        move = (x + y) % 2 == 0 ? 1 : -1;
                        re += bmpImg->imageData[x * step + y*channels + k] * cos(-2 * PI * temp) * move;
                        im += bmpImg->imageData[x * step + y*channels + k] * sin(-2 * PI * temp) * move;
                    }
                }
                value = (short)(sqrt(re*re + im*im) / sqrt(width*height));
                if (value > 0xff)
                    bmpImgFre->imageData[i * filter_step + j*channels +k] = 0xff;
                else if (value < 0)
                    bmpImgFre->imageData[i * filter_step + j*channels +k] = 0;
                else
                    bmpImgFre->imageData[i * filter_step + j*channels +k] = (unsigned char)value;
            }
        }
    }

    return bmpImgFre;
}

unsigned char study_mid_val(unsigned char *a, int num)
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
    char soble1[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    char soble2[3][3] =
    {
        {-1, 0, 1},
        {-2, 4, 2},
        {-1, 2, 1}
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
            bmpImgFilter->imageData[i * filter_step + j*channels +k] = study_mid_val(value, 9);
            /* sharpening using grad */
            bmpImgFilter->imageData[i * filter_step + j*channels +k] =
                (short)abs(value[0] * soble1[0][0] + value[1] * soble1[0][1] + value[2] * soble1[0][2] +
                         value[3] * soble1[1][0] + value[4] * soble1[1][1] + value[5] * soble1[1][2] +
                         value[6] * soble1[2][0] + value[7] * soble1[2][1] + value[8] * soble1[2][2]) + 
                (short)abs(value[0] * soble2[0][0] + value[1] * soble2[0][1] + value[2] * soble2[0][2] +
                         value[3] * soble2[1][0] + value[4] * soble2[1][1] + value[5] * soble2[1][2] +
                         value[6] * soble2[2][0] + value[7] * soble2[2][1] + value[8] * soble2[2][2]);
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
