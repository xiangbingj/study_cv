#ifndef STUDY_CV_H  
#define STUDY_CV_H
#include "zq_cv.h"

typedef struct _PerspectiveTransform
{
    float a11;
    float a12;
    float a13;
    float a21;
    float a22;
    float a23;
    float a31;
    float a32;
    float a33;
} PerspectiveTransform;
void times(PerspectiveTransform *p, PerspectiveTransform *other, PerspectiveTransform *ret_p);
void quadrilateralToQuadrilateral(PerspectiveTransform *ret_p, float x0, float y0, float x1, float y1,float x2, float y2, float x3, float y3,
                                float x0p, float y0p, float x1p, float y1p, float x2p, float y2p, float x3p, float y3p);
void quadrilateralToSquare(PerspectiveTransform *ret_p, float x0, float y0, float x1, float y1,
                            float x2, float y2, float x3, float y3) ;
void squareToQuadrilateral(PerspectiveTransform *ret_p, float x0, float y0, float x1, float y1,
                            float x2, float y2, float x3, float y3);
void buildAdjoint(PerspectiveTransform *p, PerspectiveTransform *ret_p);
void transformPoints(PerspectiveTransform *p, float *points, int len);
ZqImage *study_PerspectiveTransform(ZqImage* bmpImg);

ZqImage* study_bpp24_to_grayscale(ZqImage* bmpImg);
ZqImage* study_imgamma(ZqImage* bmpImg);
ZqImage* study_filtering(ZqImage* bmpImg);
ZqImage* study_fre_spectrum(ZqImage* bmpImg);
ZqImage *study_add_gaussian_noise(ZqImage* bmpImg);
ZqImage *study_add_salt_pepper_noise(ZqImage* bmpImg);
ZqImage *study_PerspectiveTransform_new(ZqImage* bmpImg);
ZqImage *imshear(ZqImage *img, int angle, char axis);
double *_umeyama(double *src, double *dst, double estimate_scale);

#endif