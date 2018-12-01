#ifndef STUDY_CV_H  
#define STUDY_CV_H
#include "zq_cv.h"

ZqImage* study_bpp24_to_grayscale(ZqImage* bmpImg);
ZqImage* study_imgamma(ZqImage* bmpImg);
ZqImage* study_filtering(ZqImage* bmpImg);

#endif