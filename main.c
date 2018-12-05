#include<stdio.h>
#include "zq_cv.h"
#include "study_cv.h"

int main(int argc, char* argv[])
{
    ZqImage* img = imread("lena/baby_24_red.bmp");//读取原始图像(灰度或彩色)
    int point[3][2] =
        {
            {76, 76},
            {189, 76},
            {76, 151}
        };
    double pts1[5][2] =  
            {
                {30.2946, 51.6963},
                {65.5318, 51.5014},
                {48.0252, 71.7366},
                {33.5493, 92.3655},
                {62.7299, 92.2041}
            };
    double pts2[5][2] =  
            {
                {120,97},
                {163,86},
                {121, 109},
                {99, 129},
                {139,125}
            };
    int mid_point[2] = {128, 151};
    _umeyama(&pts2[0][0], &pts1[0][0], 0);

    getchar();
    return 0;
}
