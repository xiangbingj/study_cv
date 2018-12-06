#include<stdio.h>
#include "zq_cv.h"
#include "study_cv.h"

int main(int argc, char* argv[])
{
#define PIC_SIZE 128
#define MARGIN_SIZE 48
    ZqImage* img = imread("../lena/pic_left_red.bmp");//读取原始图像(灰度或彩色)
    ZqImage* img_2ch = study_3ch_to_2ch(img);
    free(img);
    img = study_2ch_to_3ch(img_2ch);
    free(img_2ch);
    ZqImage* img_rrr = rgb_to_rrrgggbbb(img);
    free(img);
    img = rrrgggbbb_to_rgb(img_rrr);
    free(img_rrr);
    //计算标准的人脸五点坐标，转换成128*128+margin的图片格式。
    double dst[5][2] =  
        {
            {30.2946*PIC_SIZE/96, 51.6963*PIC_SIZE/112},
            {65.5318*PIC_SIZE/96, 51.5014*PIC_SIZE/112},
            {48.0252*PIC_SIZE/96, 71.7366*PIC_SIZE/112},
            {33.5493*PIC_SIZE/96, 92.3655*PIC_SIZE/112},
            {62.7299*PIC_SIZE/96, 92.2041*PIC_SIZE/112}
        };
    int i, j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<2; j++)
        {
            //平移到坐标原点进行缩放，再平移到原始坐标。
            dst[i][j] = (dst[i][j] - PIC_SIZE/2)*(PIC_SIZE - MARGIN_SIZE)/128 + PIC_SIZE/2;
        }
    }
    //待变换的图片五点坐标
    double src[5][2] =  
        {
            {120, 97},
            {163, 87},
            {130, 117},
            {126, 148},
            {163, 141}
        };
    //计算变换矩阵 3*3
    double *TT = study_umeyama(&dst[0][0], &src[0][0]);
    double (*T)[3] = TT;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            printf("T[%d][%d] = %f ", i, j, T[i][j]);
        printf("\n");
    }
    //原始图片进行相似变换
    ZqImage* imgSim = study_similarity(img, TT);
    imwrite("simResult.bmp", imgSim);
    getchar();
    return 0;
}
