#ifndef STUDY_CV_H  
#define STUDY_CV_H
#include "zq_cv.h"

//#define STUDY_DBUG
#ifdef STUDY_DBUG
#define STUDY_DBG(fmt, args...) printf(fmt, ##args)
#else
#define STUDY_DBG(fmt, args...)
#endif

ZqImage *rrrgggbbb_to_rgb(ZqImage *bmpImg);
ZqImage *rgb_to_rrrgggbbb(ZqImage *bmpImg);
ZqImage *study_2ch_to_3ch(ZqImage *img_2ch);
ZqImage *study_3ch_to_2ch(ZqImage *img_3ch);
ZqImage *study_PerspectiveTransform(ZqImage* bmpImg);
ZqImage* study_bpp24_to_grayscale(ZqImage* bmpImg);
ZqImage* study_imgamma(ZqImage* bmpImg);
ZqImage* study_filtering(ZqImage* bmpImg);
ZqImage* study_fre_spectrum(ZqImage* bmpImg);
ZqImage *study_add_gaussian_noise(ZqImage* bmpImg);
ZqImage *study_add_salt_pepper_noise(ZqImage* bmpImg);
ZqImage *study_PerspectiveTransform_new(ZqImage* bmpImg);
ZqImage *study_imshear(ZqImage *img, int angle, char axis);
double *study_umeyama(double *src, double *dst);
ZqImage *study_similarity(ZqImage* bmpImg, double *T);
#endif