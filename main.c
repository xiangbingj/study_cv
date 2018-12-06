#include<stdio.h>
#include "zq_cv.h"
#include "study_cv.h"

int main(int argc, char* argv[])
{
    ZqImage* img = imread("lena/pic_left_red.bmp");//读取原始图像(灰度或彩色)
    double dst[5][2] =  
            {
                {30.2946, 51.6963},
                {65.5318, 51.5014},
                {48.0252, 71.7366},
                {33.5493, 92.3655},
                {62.7299, 92.2041}
            };
    double src[5][2] =  
            {
                {120,97},
                {163,86},
                {131, 117},
                {127, 147},
                {162,142}
            };
    double *TT = _umeyama(&dst[0][0], &src[0][0]);
    double (*T)[3] = TT;
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            printf("T[%d][%d] = %f ", i, j, T[i][j]);
        printf("\n");
    }
    ZqImage* imgSim = study_similarity(img, TT);
    imwrite("simResult.bmp", imgSim);
    getchar();
    return 0;
}
