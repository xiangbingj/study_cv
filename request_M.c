#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Power(a, b) pow(a, b)
int main()
{
    double x1 = 30.2946;
    double x2 = 65.5318;
    double x3 = 48.0252;
    double x4 = 33.5493;
    double x5 = 62.7299;
    double y1 = 51.6963;
    double y2 = 51.5014;
    double y3 = 71.7366;
    double y4 = 92.3655;
    double y5 = 92.2041;
    double u1 = 120;
    double u2 = 163;
    double u3 = 121;
    double u4 = 99;
    double u5 = 139;
    double v1 = 97;
    double v2 = 86;
    double v3 = 109;
    double v4 = 129;
    double v5 = 125;
double M[4][4] = {0.0};
M[1][1] = (-(u4*x2*Power(y1,2)) - u5*x2*Power(y1,2) - u4*x3*Power(y1,2) - u5*x3*Power(y1,2) + 3*u4*x4*Power(y1,2) - u5*x4*Power(y1,2) - u4*x5*Power(y1,2) + 3*u5*x5*Power(y1,2) + u4*x1*y1*y2 + u5*x1*y1*y2 - 3*u1*x2*y1*y2 + u4*x2*y1*y2 + u5*x2*y1*y2 + u1*x3*y1*y2 + 
     u1*x4*y1*y2 - 2*u4*x4*y1*y2 + u1*x5*y1*y2 - 2*u5*x5*y1*y2 + 3*u1*x1*Power(y2,2) - u4*x1*Power(y2,2) - u5*x1*Power(y2,2) - u1*x3*Power(y2,2) - u4*x3*Power(y2,2) - u5*x3*Power(y2,2) - u1*x4*Power(y2,2) + 3*u4*x4*Power(y2,2) - u5*x4*Power(y2,2) - 
     u1*x5*Power(y2,2) - u4*x5*Power(y2,2) + 3*u5*x5*Power(y2,2) + u4*x1*y1*y3 + u5*x1*y1*y3 + u1*x2*y1*y3 - 3*u1*x3*y1*y3 + u4*x3*y1*y3 + u5*x3*y1*y3 + u1*x4*y1*y3 - 2*u4*x4*y1*y3 + u1*x5*y1*y3 - 2*u5*x5*y1*y3 - 2*u1*x1*y2*y3 + u1*x2*y2*y3 + u4*x2*y2*y3 + 
     u5*x2*y2*y3 + u1*x3*y2*y3 + u4*x3*y2*y3 + u5*x3*y2*y3 - 2*u4*x4*y2*y3 - 2*u5*x5*y2*y3 + 3*u1*x1*Power(y3,2) - u4*x1*Power(y3,2) - u5*x1*Power(y3,2) - u1*x2*Power(y3,2) - u4*x2*Power(y3,2) - u5*x2*Power(y3,2) - u1*x4*Power(y3,2) + 3*u4*x4*Power(y3,2) - 
     u5*x4*Power(y3,2) - u1*x5*Power(y3,2) - u4*x5*Power(y3,2) + 3*u5*x5*Power(y3,2) - 3*u4*x1*y1*y4 + u5*x1*y1*y4 + u1*x2*y1*y4 + u4*x2*y1*y4 + u1*x3*y1*y4 + u4*x3*y1*y4 - 3*u1*x4*y1*y4 + u5*x4*y1*y4 + u1*x5*y1*y4 + u4*x5*y1*y4 - 2*u5*x5*y1*y4 - 
     2*u1*x1*y2*y4 + u4*x1*y2*y4 + u1*x2*y2*y4 - 3*u4*x2*y2*y4 + u5*x2*y2*y4 + u4*x3*y2*y4 + u1*x4*y2*y4 + u5*x4*y2*y4 + u4*x5*y2*y4 - 2*u5*x5*y2*y4 - 2*u1*x1*y3*y4 + u4*x1*y3*y4 + u4*x2*y3*y4 + u1*x3*y3*y4 - 3*u4*x3*y3*y4 + u5*x3*y3*y4 + u1*x4*y3*y4 + 
     u5*x4*y3*y4 + u4*x5*y3*y4 - 2*u5*x5*y3*y4 + 3*u1*x1*Power(y4,2) - u5*x1*Power(y4,2) - u1*x2*Power(y4,2) - u5*x2*Power(y4,2) - u1*x3*Power(y4,2) - u5*x3*Power(y4,2) - u1*x5*Power(y4,2) + 3*u5*x5*Power(y4,2) + u4*x1*y1*y5 - 3*u5*x1*y1*y5 + u1*x2*y1*y5 + 
     u5*x2*y1*y5 + u1*x3*y1*y5 + u5*x3*y1*y5 + u1*x4*y1*y5 - 2*u4*x4*y1*y5 + u5*x4*y1*y5 - 3*u1*x5*y1*y5 + u4*x5*y1*y5 - 2*u1*x1*y2*y5 + u5*x1*y2*y5 + u1*x2*y2*y5 + u4*x2*y2*y5 - 3*u5*x2*y2*y5 + u5*x3*y2*y5 - 2*u4*x4*y2*y5 + u5*x4*y2*y5 + u1*x5*y2*y5 + 
     u4*x5*y2*y5 - 2*u1*x1*y3*y5 + u5*x1*y3*y5 + u5*x2*y3*y5 + u1*x3*y3*y5 + u4*x3*y3*y5 - 3*u5*x3*y3*y5 - 2*u4*x4*y3*y5 + u5*x4*y3*y5 + u1*x5*y3*y5 + u4*x5*y3*y5 - 2*u1*x1*y4*y5 + u4*x1*y4*y5 + u5*x1*y4*y5 + u4*x2*y4*y5 + u5*x2*y4*y5 + u4*x3*y4*y5 + 
     u5*x3*y4*y5 + u1*x4*y4*y5 - 3*u5*x4*y4*y5 + u1*x5*y4*y5 - 3*u4*x5*y4*y5 + 3*u1*x1*Power(y5,2) - u4*x1*Power(y5,2) - u1*x2*Power(y5,2) - u4*x2*Power(y5,2) - u1*x3*Power(y5,2) - u4*x3*Power(y5,2) - u1*x4*Power(y5,2) + 3*u4*x4*Power(y5,2) + 
     u3*(-(x4*Power(y1,2)) - x5*Power(y1,2) + x1*y1*y2 - x1*Power(y2,2) - x4*Power(y2,2) - x5*Power(y2,2) - 3*x1*y1*y3 + x4*y1*y3 + x5*y1*y3 + x1*y2*y3 + x4*y2*y3 + x5*y2*y3 + x1*y1*y4 + x4*y1*y4 + x4*y2*y4 + x1*y3*y4 - 3*x4*y3*y4 + x5*y3*y4 - 
        x1*Power(y4,2) - x5*Power(y4,2) + x1*y1*y5 + x5*y1*y5 + x5*y2*y5 + x1*y3*y5 + x4*y3*y5 - 3*x5*y3*y5 + x4*y4*y5 + x5*y4*y5 - x1*Power(y5,2) - x4*Power(y5,2) + 
        x3*(3*Power(y1,2) + 3*Power(y2,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y2*(y4 + y5) - 2*y1*(y2 + y4 + y5)) + x2*(-Power(y1,2) + y1*(y2 + y3) + y3*y4 - Power(y4,2) + y3*y5 - Power(y5,2) + y2*(-3*y3 + y4 + y5))) + 
     u2*(-(x4*Power(y1,2)) - x5*Power(y1,2) - 3*x1*y1*y2 + x4*y1*y2 + x5*y1*y2 + x1*y1*y3 + x1*y2*y3 + x4*y2*y3 + x5*y2*y3 - x1*Power(y3,2) - x4*Power(y3,2) - x5*Power(y3,2) + x1*y1*y4 + x4*y1*y4 + x1*y2*y4 - 3*x4*y2*y4 + x5*y2*y4 + x4*y3*y4 - 
        x1*Power(y4,2) - x5*Power(y4,2) + x1*y1*y5 + x5*y1*y5 + x1*y2*y5 + x4*y2*y5 - 3*x5*y2*y5 + x5*y3*y5 + x4*y4*y5 + x5*y4*y5 - x1*Power(y5,2) - x4*Power(y5,2) + 
        x3*(-Power(y1,2) + y1*(y2 + y3) + y3*y4 - Power(y4,2) + y3*y5 - Power(y5,2) + y2*(-3*y3 + y4 + y5)) + x2*(3*Power(y1,2) + 3*Power(y3,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y3*(y4 + y5) - 2*y1*(y3 + y4 + y5))))/
   (3*Power(x4,2)*Power(y1,2) - 2*x4*x5*Power(y1,2) + 3*Power(x5,2)*Power(y1,2) + 2*x1*x4*y1*y2 - 2*Power(x4,2)*y1*y2 + 2*x1*x5*y1*y2 - 2*Power(x5,2)*y1*y2 + 3*Power(x1,2)*Power(y2,2) - 2*x1*x4*Power(y2,2) + 3*Power(x4,2)*Power(y2,2) - 
     2*x1*x5*Power(y2,2) - 2*x4*x5*Power(y2,2) + 3*Power(x5,2)*Power(y2,2) + 2*x1*x4*y1*y3 - 2*Power(x4,2)*y1*y3 + 2*x1*x5*y1*y3 - 2*Power(x5,2)*y1*y3 - 2*Power(x1,2)*y2*y3 - 2*Power(x4,2)*y2*y3 - 2*Power(x5,2)*y2*y3 + 3*Power(x1,2)*Power(y3,2) - 
     2*x1*x4*Power(y3,2) + 3*Power(x4,2)*Power(y3,2) - 2*x1*x5*Power(y3,2) - 2*x4*x5*Power(y3,2) + 3*Power(x5,2)*Power(y3,2) - 6*x1*x4*y1*y4 + 2*x1*x5*y1*y4 + 2*x4*x5*y1*y4 - 2*Power(x5,2)*y1*y4 - 2*Power(x1,2)*y2*y4 + 2*x1*x4*y2*y4 + 2*x4*x5*y2*y4 - 
     2*Power(x5,2)*y2*y4 - 2*Power(x1,2)*y3*y4 + 2*x1*x4*y3*y4 + 2*x4*x5*y3*y4 - 2*Power(x5,2)*y3*y4 + 3*Power(x1,2)*Power(y4,2) - 2*x1*x5*Power(y4,2) + 3*Power(x5,2)*Power(y4,2) + 2*x1*x4*y1*y5 - 2*Power(x4,2)*y1*y5 - 6*x1*x5*y1*y5 + 2*x4*x5*y1*y5 - 
     2*Power(x1,2)*y2*y5 - 2*Power(x4,2)*y2*y5 + 2*x1*x5*y2*y5 + 2*x4*x5*y2*y5 - 2*Power(x1,2)*y3*y5 - 2*Power(x4,2)*y3*y5 + 2*x1*x5*y3*y5 + 2*x4*x5*y3*y5 - 2*Power(x1,2)*y4*y5 + 2*x1*x4*y4*y5 + 2*x1*x5*y4*y5 - 6*x4*x5*y4*y5 + 3*Power(x1,2)*Power(y5,2) - 
     2*x1*x4*Power(y5,2) + 3*Power(x4,2)*Power(y5,2) + Power(x3,2)*(3*Power(y1,2) + 3*Power(y2,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y2*(y4 + y5) - 2*y1*(y2 + y4 + y5)) + 
     Power(x2,2)*(3*Power(y1,2) + 3*Power(y3,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y3*(y4 + y5) - 2*y1*(y3 + y4 + y5)) - 
     2*x2*(x5*Power(y1,2) + 3*x1*y1*y2 - x5*y1*y2 - x1*y1*y3 - x1*y2*y3 - x5*y2*y3 + x1*Power(y3,2) + x5*Power(y3,2) - x1*y1*y4 - x1*y2*y4 - x5*y2*y4 + x1*Power(y4,2) + x5*Power(y4,2) - x1*y1*y5 - x5*y1*y5 - x1*y2*y5 + 3*x5*y2*y5 - x5*y3*y5 - x5*y4*y5 + 
        x1*Power(y5,2) + x3*(Power(y1,2) - y1*(y2 + y3) - y3*y4 + Power(y4,2) + y2*(3*y3 - y4 - y5) - y3*y5 + Power(y5,2)) + x4*(Power(y1,2) + Power(y3,2) - y3*y4 - y1*(y2 + y4) - y4*y5 + Power(y5,2) - y2*(y3 - 3*y4 + y5))) - 
     2*x3*(x4*(Power(y1,2) + Power(y2,2) + 3*y3*y4 - y1*(y3 + y4) - y2*(y3 + y4) - y3*y5 - y4*y5 + Power(y5,2)) + x5*(Power(y1,2) + Power(y2,2) - y3*y4 + Power(y4,2) + 3*y3*y5 - y4*y5 - y1*(y3 + y5) - y2*(y3 + y5)) - 
        x1*(-Power(y2,2) + y2*y3 + y3*y4 - Power(y4,2) + y3*y5 - Power(y5,2) + y1*(y2 - 3*y3 + y4 + y5)))); 
M[1][2] = (-(v4*x2*Power(y1,2)) - v5*x2*Power(y1,2) - v4*x3*Power(y1,2) - v5*x3*Power(y1,2) + 3*v4*x4*Power(y1,2) - v5*x4*Power(y1,2) - v4*x5*Power(y1,2) + 3*v5*x5*Power(y1,2) + v4*x1*y1*y2 + v5*x1*y1*y2 - 3*v1*x2*y1*y2 + v4*x2*y1*y2 + v5*x2*y1*y2 + v1*x3*y1*y2 + 
     v1*x4*y1*y2 - 2*v4*x4*y1*y2 + v1*x5*y1*y2 - 2*v5*x5*y1*y2 + 3*v1*x1*Power(y2,2) - v4*x1*Power(y2,2) - v5*x1*Power(y2,2) - v1*x3*Power(y2,2) - v4*x3*Power(y2,2) - v5*x3*Power(y2,2) - v1*x4*Power(y2,2) + 3*v4*x4*Power(y2,2) - v5*x4*Power(y2,2) - 
     v1*x5*Power(y2,2) - v4*x5*Power(y2,2) + 3*v5*x5*Power(y2,2) + v4*x1*y1*y3 + v5*x1*y1*y3 + v1*x2*y1*y3 - 3*v1*x3*y1*y3 + v4*x3*y1*y3 + v5*x3*y1*y3 + v1*x4*y1*y3 - 2*v4*x4*y1*y3 + v1*x5*y1*y3 - 2*v5*x5*y1*y3 - 2*v1*x1*y2*y3 + v1*x2*y2*y3 + v4*x2*y2*y3 + 
     v5*x2*y2*y3 + v1*x3*y2*y3 + v4*x3*y2*y3 + v5*x3*y2*y3 - 2*v4*x4*y2*y3 - 2*v5*x5*y2*y3 + 3*v1*x1*Power(y3,2) - v4*x1*Power(y3,2) - v5*x1*Power(y3,2) - v1*x2*Power(y3,2) - v4*x2*Power(y3,2) - v5*x2*Power(y3,2) - v1*x4*Power(y3,2) + 3*v4*x4*Power(y3,2) - 
     v5*x4*Power(y3,2) - v1*x5*Power(y3,2) - v4*x5*Power(y3,2) + 3*v5*x5*Power(y3,2) - 3*v4*x1*y1*y4 + v5*x1*y1*y4 + v1*x2*y1*y4 + v4*x2*y1*y4 + v1*x3*y1*y4 + v4*x3*y1*y4 - 3*v1*x4*y1*y4 + v5*x4*y1*y4 + v1*x5*y1*y4 + v4*x5*y1*y4 - 2*v5*x5*y1*y4 - 
     2*v1*x1*y2*y4 + v4*x1*y2*y4 + v1*x2*y2*y4 - 3*v4*x2*y2*y4 + v5*x2*y2*y4 + v4*x3*y2*y4 + v1*x4*y2*y4 + v5*x4*y2*y4 + v4*x5*y2*y4 - 2*v5*x5*y2*y4 - 2*v1*x1*y3*y4 + v4*x1*y3*y4 + v4*x2*y3*y4 + v1*x3*y3*y4 - 3*v4*x3*y3*y4 + v5*x3*y3*y4 + v1*x4*y3*y4 + 
     v5*x4*y3*y4 + v4*x5*y3*y4 - 2*v5*x5*y3*y4 + 3*v1*x1*Power(y4,2) - v5*x1*Power(y4,2) - v1*x2*Power(y4,2) - v5*x2*Power(y4,2) - v1*x3*Power(y4,2) - v5*x3*Power(y4,2) - v1*x5*Power(y4,2) + 3*v5*x5*Power(y4,2) + v4*x1*y1*y5 - 3*v5*x1*y1*y5 + v1*x2*y1*y5 + 
     v5*x2*y1*y5 + v1*x3*y1*y5 + v5*x3*y1*y5 + v1*x4*y1*y5 - 2*v4*x4*y1*y5 + v5*x4*y1*y5 - 3*v1*x5*y1*y5 + v4*x5*y1*y5 - 2*v1*x1*y2*y5 + v5*x1*y2*y5 + v1*x2*y2*y5 + v4*x2*y2*y5 - 3*v5*x2*y2*y5 + v5*x3*y2*y5 - 2*v4*x4*y2*y5 + v5*x4*y2*y5 + v1*x5*y2*y5 + 
     v4*x5*y2*y5 - 2*v1*x1*y3*y5 + v5*x1*y3*y5 + v5*x2*y3*y5 + v1*x3*y3*y5 + v4*x3*y3*y5 - 3*v5*x3*y3*y5 - 2*v4*x4*y3*y5 + v5*x4*y3*y5 + v1*x5*y3*y5 + v4*x5*y3*y5 - 2*v1*x1*y4*y5 + v4*x1*y4*y5 + v5*x1*y4*y5 + v4*x2*y4*y5 + v5*x2*y4*y5 + v4*x3*y4*y5 + 
     v5*x3*y4*y5 + v1*x4*y4*y5 - 3*v5*x4*y4*y5 + v1*x5*y4*y5 - 3*v4*x5*y4*y5 + 3*v1*x1*Power(y5,2) - v4*x1*Power(y5,2) - v1*x2*Power(y5,2) - v4*x2*Power(y5,2) - v1*x3*Power(y5,2) - v4*x3*Power(y5,2) - v1*x4*Power(y5,2) + 3*v4*x4*Power(y5,2) + 
     v3*(-(x4*Power(y1,2)) - x5*Power(y1,2) + x1*y1*y2 - x1*Power(y2,2) - x4*Power(y2,2) - x5*Power(y2,2) - 3*x1*y1*y3 + x4*y1*y3 + x5*y1*y3 + x1*y2*y3 + x4*y2*y3 + x5*y2*y3 + x1*y1*y4 + x4*y1*y4 + x4*y2*y4 + x1*y3*y4 - 3*x4*y3*y4 + x5*y3*y4 - 
        x1*Power(y4,2) - x5*Power(y4,2) + x1*y1*y5 + x5*y1*y5 + x5*y2*y5 + x1*y3*y5 + x4*y3*y5 - 3*x5*y3*y5 + x4*y4*y5 + x5*y4*y5 - x1*Power(y5,2) - x4*Power(y5,2) + 
        x3*(3*Power(y1,2) + 3*Power(y2,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y2*(y4 + y5) - 2*y1*(y2 + y4 + y5)) + x2*(-Power(y1,2) + y1*(y2 + y3) + y3*y4 - Power(y4,2) + y3*y5 - Power(y5,2) + y2*(-3*y3 + y4 + y5))) + 
     v2*(-(x4*Power(y1,2)) - x5*Power(y1,2) - 3*x1*y1*y2 + x4*y1*y2 + x5*y1*y2 + x1*y1*y3 + x1*y2*y3 + x4*y2*y3 + x5*y2*y3 - x1*Power(y3,2) - x4*Power(y3,2) - x5*Power(y3,2) + x1*y1*y4 + x4*y1*y4 + x1*y2*y4 - 3*x4*y2*y4 + x5*y2*y4 + x4*y3*y4 - 
        x1*Power(y4,2) - x5*Power(y4,2) + x1*y1*y5 + x5*y1*y5 + x1*y2*y5 + x4*y2*y5 - 3*x5*y2*y5 + x5*y3*y5 + x4*y4*y5 + x5*y4*y5 - x1*Power(y5,2) - x4*Power(y5,2) + 
        x3*(-Power(y1,2) + y1*(y2 + y3) + y3*y4 - Power(y4,2) + y3*y5 - Power(y5,2) + y2*(-3*y3 + y4 + y5)) + x2*(3*Power(y1,2) + 3*Power(y3,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y3*(y4 + y5) - 2*y1*(y3 + y4 + y5))))/
   (3*Power(x4,2)*Power(y1,2) - 2*x4*x5*Power(y1,2) + 3*Power(x5,2)*Power(y1,2) + 2*x1*x4*y1*y2 - 2*Power(x4,2)*y1*y2 + 2*x1*x5*y1*y2 - 2*Power(x5,2)*y1*y2 + 3*Power(x1,2)*Power(y2,2) - 2*x1*x4*Power(y2,2) + 3*Power(x4,2)*Power(y2,2) - 
     2*x1*x5*Power(y2,2) - 2*x4*x5*Power(y2,2) + 3*Power(x5,2)*Power(y2,2) + 2*x1*x4*y1*y3 - 2*Power(x4,2)*y1*y3 + 2*x1*x5*y1*y3 - 2*Power(x5,2)*y1*y3 - 2*Power(x1,2)*y2*y3 - 2*Power(x4,2)*y2*y3 - 2*Power(x5,2)*y2*y3 + 3*Power(x1,2)*Power(y3,2) - 
     2*x1*x4*Power(y3,2) + 3*Power(x4,2)*Power(y3,2) - 2*x1*x5*Power(y3,2) - 2*x4*x5*Power(y3,2) + 3*Power(x5,2)*Power(y3,2) - 6*x1*x4*y1*y4 + 2*x1*x5*y1*y4 + 2*x4*x5*y1*y4 - 2*Power(x5,2)*y1*y4 - 2*Power(x1,2)*y2*y4 + 2*x1*x4*y2*y4 + 2*x4*x5*y2*y4 - 
     2*Power(x5,2)*y2*y4 - 2*Power(x1,2)*y3*y4 + 2*x1*x4*y3*y4 + 2*x4*x5*y3*y4 - 2*Power(x5,2)*y3*y4 + 3*Power(x1,2)*Power(y4,2) - 2*x1*x5*Power(y4,2) + 3*Power(x5,2)*Power(y4,2) + 2*x1*x4*y1*y5 - 2*Power(x4,2)*y1*y5 - 6*x1*x5*y1*y5 + 2*x4*x5*y1*y5 - 
     2*Power(x1,2)*y2*y5 - 2*Power(x4,2)*y2*y5 + 2*x1*x5*y2*y5 + 2*x4*x5*y2*y5 - 2*Power(x1,2)*y3*y5 - 2*Power(x4,2)*y3*y5 + 2*x1*x5*y3*y5 + 2*x4*x5*y3*y5 - 2*Power(x1,2)*y4*y5 + 2*x1*x4*y4*y5 + 2*x1*x5*y4*y5 - 6*x4*x5*y4*y5 + 3*Power(x1,2)*Power(y5,2) - 
     2*x1*x4*Power(y5,2) + 3*Power(x4,2)*Power(y5,2) + Power(x3,2)*(3*Power(y1,2) + 3*Power(y2,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y2*(y4 + y5) - 2*y1*(y2 + y4 + y5)) + 
     Power(x2,2)*(3*Power(y1,2) + 3*Power(y3,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y3*(y4 + y5) - 2*y1*(y3 + y4 + y5)) - 
     2*x2*(x5*Power(y1,2) + 3*x1*y1*y2 - x5*y1*y2 - x1*y1*y3 - x1*y2*y3 - x5*y2*y3 + x1*Power(y3,2) + x5*Power(y3,2) - x1*y1*y4 - x1*y2*y4 - x5*y2*y4 + x1*Power(y4,2) + x5*Power(y4,2) - x1*y1*y5 - x5*y1*y5 - x1*y2*y5 + 3*x5*y2*y5 - x5*y3*y5 - x5*y4*y5 + 
        x1*Power(y5,2) + x3*(Power(y1,2) - y1*(y2 + y3) - y3*y4 + Power(y4,2) + y2*(3*y3 - y4 - y5) - y3*y5 + Power(y5,2)) + x4*(Power(y1,2) + Power(y3,2) - y3*y4 - y1*(y2 + y4) - y4*y5 + Power(y5,2) - y2*(y3 - 3*y4 + y5))) - 
     2*x3*(x4*(Power(y1,2) + Power(y2,2) + 3*y3*y4 - y1*(y3 + y4) - y2*(y3 + y4) - y3*y5 - y4*y5 + Power(y5,2)) + x5*(Power(y1,2) + Power(y2,2) - y3*y4 + Power(y4,2) + 3*y3*y5 - y4*y5 - y1*(y3 + y5) - y2*(y3 + y5)) - 
        x1*(-Power(y2,2) + y2*y3 + y3*y4 - Power(y4,2) + y3*y5 - Power(y5,2) + y1*(y2 - 3*y3 + y4 + y5))));
M[2][1] = (u4*x1*x2*y1 + u5*x1*x2*y1 + 3*u1*Power(x2,2)*y1 - u4*Power(x2,2)*y1 - u5*Power(x2,2)*y1 + u4*x1*x3*y1 + u5*x1*x3*y1 - 2*u1*x2*x3*y1 + 3*u1*Power(x3,2)*y1 - u4*Power(x3,2)*y1 - u5*Power(x3,2)*y1 - 3*u4*x1*x4*y1 + u5*x1*x4*y1 - 2*u1*x2*x4*y1 + u4*x2*x4*y1 - 
     2*u1*x3*x4*y1 + u4*x3*x4*y1 + 3*u1*Power(x4,2)*y1 - u5*Power(x4,2)*y1 + u4*x1*x5*y1 - 3*u5*x1*x5*y1 - 2*u1*x2*x5*y1 + u5*x2*x5*y1 - 2*u1*x3*x5*y1 + u5*x3*x5*y1 - 2*u1*x4*x5*y1 + u4*x4*x5*y1 + u5*x4*x5*y1 + 3*u1*Power(x5,2)*y1 - u4*Power(x5,2)*y1 - 
     u4*Power(x1,2)*y2 - u5*Power(x1,2)*y2 - 3*u1*x1*x2*y2 + u4*x1*x2*y2 + u5*x1*x2*y2 + u1*x1*x3*y2 + u1*x2*x3*y2 + u4*x2*x3*y2 + u5*x2*x3*y2 - u1*Power(x3,2)*y2 - u4*Power(x3,2)*y2 - u5*Power(x3,2)*y2 + u1*x1*x4*y2 + u4*x1*x4*y2 + u1*x2*x4*y2 - 
     3*u4*x2*x4*y2 + u5*x2*x4*y2 + u4*x3*x4*y2 - u1*Power(x4,2)*y2 - u5*Power(x4,2)*y2 + u1*x1*x5*y2 + u5*x1*x5*y2 + u1*x2*x5*y2 + u4*x2*x5*y2 - 3*u5*x2*x5*y2 + u5*x3*x5*y2 + u4*x4*x5*y2 + u5*x4*x5*y2 - u1*Power(x5,2)*y2 - u4*Power(x5,2)*y2 - 
     u4*Power(x1,2)*y3 - u5*Power(x1,2)*y3 + u1*x1*x2*y3 - u1*Power(x2,2)*y3 - u4*Power(x2,2)*y3 - u5*Power(x2,2)*y3 - 3*u1*x1*x3*y3 + u4*x1*x3*y3 + u5*x1*x3*y3 + u1*x2*x3*y3 + u4*x2*x3*y3 + u5*x2*x3*y3 + u1*x1*x4*y3 + u4*x1*x4*y3 + u4*x2*x4*y3 + 
     u1*x3*x4*y3 - 3*u4*x3*x4*y3 + u5*x3*x4*y3 - u1*Power(x4,2)*y3 - u5*Power(x4,2)*y3 + u1*x1*x5*y3 + u5*x1*x5*y3 + u5*x2*x5*y3 + u1*x3*x5*y3 + u4*x3*x5*y3 - 3*u5*x3*x5*y3 + u4*x4*x5*y3 + u5*x4*x5*y3 - u1*Power(x5,2)*y3 - u4*Power(x5,2)*y3 + 
     3*u4*Power(x1,2)*y4 - u5*Power(x1,2)*y4 + u1*x1*x2*y4 - 2*u4*x1*x2*y4 - u1*Power(x2,2)*y4 + 3*u4*Power(x2,2)*y4 - u5*Power(x2,2)*y4 + u1*x1*x3*y4 - 2*u4*x1*x3*y4 - 2*u4*x2*x3*y4 - u1*Power(x3,2)*y4 + 3*u4*Power(x3,2)*y4 - u5*Power(x3,2)*y4 - 
     3*u1*x1*x4*y4 + u5*x1*x4*y4 + u1*x2*x4*y4 + u5*x2*x4*y4 + u1*x3*x4*y4 + u5*x3*x4*y4 + u1*x1*x5*y4 - 2*u4*x1*x5*y4 + u5*x1*x5*y4 - 2*u4*x2*x5*y4 + u5*x2*x5*y4 - 2*u4*x3*x5*y4 + u5*x3*x5*y4 + u1*x4*x5*y4 - 3*u5*x4*x5*y4 - u1*Power(x5,2)*y4 + 
     3*u4*Power(x5,2)*y4 - u4*Power(x1,2)*y5 + 3*u5*Power(x1,2)*y5 + u1*x1*x2*y5 - 2*u5*x1*x2*y5 - u1*Power(x2,2)*y5 - u4*Power(x2,2)*y5 + 3*u5*Power(x2,2)*y5 + u1*x1*x3*y5 - 2*u5*x1*x3*y5 - 2*u5*x2*x3*y5 - u1*Power(x3,2)*y5 - u4*Power(x3,2)*y5 + 
     3*u5*Power(x3,2)*y5 + u1*x1*x4*y5 + u4*x1*x4*y5 - 2*u5*x1*x4*y5 + u4*x2*x4*y5 - 2*u5*x2*x4*y5 + u4*x3*x4*y5 - 2*u5*x3*x4*y5 - u1*Power(x4,2)*y5 + 3*u5*Power(x4,2)*y5 - 3*u1*x1*x5*y5 + u4*x1*x5*y5 + u1*x2*x5*y5 + u4*x2*x5*y5 + u1*x3*x5*y5 + 
     u4*x3*x5*y5 + u1*x4*x5*y5 - 3*u4*x4*x5*y5 + u3*(x3*x4*y1 - Power(x4,2)*y1 + x3*x5*y1 - Power(x5,2)*y1 + x3*x4*y2 - Power(x4,2)*y2 + x3*x5*y2 - Power(x5,2)*y2 + 3*Power(x4,2)*y3 - 2*x4*x5*y3 + 3*Power(x5,2)*y3 - 3*x3*x4*y4 + x3*x5*y4 + x4*x5*y4 - 
        Power(x5,2)*y4 + x3*x4*y5 - Power(x4,2)*y5 - 3*x3*x5*y5 + x4*x5*y5 - Power(x2,2)*(y1 - 3*y3 + y4 + y5) - Power(x1,2)*(y2 - 3*y3 + y4 + y5) + x2*(x4*(y2 - 2*y3 + y4) + x5*(y2 - 2*y3 + y5) + x3*(y1 - 3*y2 + y4 + y5)) + 
        x1*(x4*y1 + x5*y1 + x2*(y1 + y2 - 2*y3) - 2*x4*y3 - 2*x5*y3 + x4*y4 + x5*y5 + x3*(-3*y1 + y2 + y4 + y5))) + 
     u2*(-(Power(x3,2)*y1) - Power(x4,2)*y1 - Power(x5,2)*y1 + 3*Power(x3,2)*y2 - 2*x3*x4*y2 + 3*Power(x4,2)*y2 - 2*x3*x5*y2 - 2*x4*x5*y2 + 3*Power(x5,2)*y2 + x3*x4*y3 - Power(x4,2)*y3 + x3*x5*y3 - Power(x5,2)*y3 - Power(x3,2)*y4 + x3*x4*y4 + x4*x5*y4 - 
        Power(x5,2)*y4 + Power(x1,2)*(3*y2 - y3 - y4 - y5) - Power(x3,2)*y5 - Power(x4,2)*y5 + x3*x5*y5 + x4*x5*y5 + x2*(x5*(y1 + y3 + y4 - 3*y5) + x4*(y1 + y3 - 3*y4 + y5) + x3*(y1 - 3*y3 + y4 + y5)) + 
        x1*(x4*y1 + x5*y1 - 2*x4*y2 - 2*x5*y2 + x3*(y1 - 2*y2 + y3) + x4*y4 + x5*y5 + x2*(-3*y1 + y3 + y4 + y5))))/
   (3*Power(x4,2)*Power(y1,2) - 2*x4*x5*Power(y1,2) + 3*Power(x5,2)*Power(y1,2) + 2*x1*x4*y1*y2 - 2*Power(x4,2)*y1*y2 + 2*x1*x5*y1*y2 - 2*Power(x5,2)*y1*y2 + 3*Power(x1,2)*Power(y2,2) - 2*x1*x4*Power(y2,2) + 3*Power(x4,2)*Power(y2,2) - 
     2*x1*x5*Power(y2,2) - 2*x4*x5*Power(y2,2) + 3*Power(x5,2)*Power(y2,2) + 2*x1*x4*y1*y3 - 2*Power(x4,2)*y1*y3 + 2*x1*x5*y1*y3 - 2*Power(x5,2)*y1*y3 - 2*Power(x1,2)*y2*y3 - 2*Power(x4,2)*y2*y3 - 2*Power(x5,2)*y2*y3 + 3*Power(x1,2)*Power(y3,2) - 
     2*x1*x4*Power(y3,2) + 3*Power(x4,2)*Power(y3,2) - 2*x1*x5*Power(y3,2) - 2*x4*x5*Power(y3,2) + 3*Power(x5,2)*Power(y3,2) - 6*x1*x4*y1*y4 + 2*x1*x5*y1*y4 + 2*x4*x5*y1*y4 - 2*Power(x5,2)*y1*y4 - 2*Power(x1,2)*y2*y4 + 2*x1*x4*y2*y4 + 2*x4*x5*y2*y4 - 
     2*Power(x5,2)*y2*y4 - 2*Power(x1,2)*y3*y4 + 2*x1*x4*y3*y4 + 2*x4*x5*y3*y4 - 2*Power(x5,2)*y3*y4 + 3*Power(x1,2)*Power(y4,2) - 2*x1*x5*Power(y4,2) + 3*Power(x5,2)*Power(y4,2) + 2*x1*x4*y1*y5 - 2*Power(x4,2)*y1*y5 - 6*x1*x5*y1*y5 + 2*x4*x5*y1*y5 - 
     2*Power(x1,2)*y2*y5 - 2*Power(x4,2)*y2*y5 + 2*x1*x5*y2*y5 + 2*x4*x5*y2*y5 - 2*Power(x1,2)*y3*y5 - 2*Power(x4,2)*y3*y5 + 2*x1*x5*y3*y5 + 2*x4*x5*y3*y5 - 2*Power(x1,2)*y4*y5 + 2*x1*x4*y4*y5 + 2*x1*x5*y4*y5 - 6*x4*x5*y4*y5 + 3*Power(x1,2)*Power(y5,2) - 
     2*x1*x4*Power(y5,2) + 3*Power(x4,2)*Power(y5,2) + Power(x3,2)*(3*Power(y1,2) + 3*Power(y2,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y2*(y4 + y5) - 2*y1*(y2 + y4 + y5)) + 
     Power(x2,2)*(3*Power(y1,2) + 3*Power(y3,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y3*(y4 + y5) - 2*y1*(y3 + y4 + y5)) - 
     2*x2*(x5*Power(y1,2) + 3*x1*y1*y2 - x5*y1*y2 - x1*y1*y3 - x1*y2*y3 - x5*y2*y3 + x1*Power(y3,2) + x5*Power(y3,2) - x1*y1*y4 - x1*y2*y4 - x5*y2*y4 + x1*Power(y4,2) + x5*Power(y4,2) - x1*y1*y5 - x5*y1*y5 - x1*y2*y5 + 3*x5*y2*y5 - x5*y3*y5 - x5*y4*y5 + 
        x1*Power(y5,2) + x3*(Power(y1,2) - y1*(y2 + y3) - y3*y4 + Power(y4,2) + y2*(3*y3 - y4 - y5) - y3*y5 + Power(y5,2)) + x4*(Power(y1,2) + Power(y3,2) - y3*y4 - y1*(y2 + y4) - y4*y5 + Power(y5,2) - y2*(y3 - 3*y4 + y5))) - 
     2*x3*(x4*(Power(y1,2) + Power(y2,2) + 3*y3*y4 - y1*(y3 + y4) - y2*(y3 + y4) - y3*y5 - y4*y5 + Power(y5,2)) + x5*(Power(y1,2) + Power(y2,2) - y3*y4 + Power(y4,2) + 3*y3*y5 - y4*y5 - y1*(y3 + y5) - y2*(y3 + y5)) - 
        x1*(-Power(y2,2) + y2*y3 + y3*y4 - Power(y4,2) + y3*y5 - Power(y5,2) + y1*(y2 - 3*y3 + y4 + y5))));
M[2][2] = (v4*x1*x2*y1 + v5*x1*x2*y1 + 3*v1*Power(x2,2)*y1 - v4*Power(x2,2)*y1 - v5*Power(x2,2)*y1 + v4*x1*x3*y1 + v5*x1*x3*y1 - 2*v1*x2*x3*y1 + 3*v1*Power(x3,2)*y1 - v4*Power(x3,2)*y1 - v5*Power(x3,2)*y1 - 3*v4*x1*x4*y1 + v5*x1*x4*y1 - 2*v1*x2*x4*y1 + v4*x2*x4*y1 - 
     2*v1*x3*x4*y1 + v4*x3*x4*y1 + 3*v1*Power(x4,2)*y1 - v5*Power(x4,2)*y1 + v4*x1*x5*y1 - 3*v5*x1*x5*y1 - 2*v1*x2*x5*y1 + v5*x2*x5*y1 - 2*v1*x3*x5*y1 + v5*x3*x5*y1 - 2*v1*x4*x5*y1 + v4*x4*x5*y1 + v5*x4*x5*y1 + 3*v1*Power(x5,2)*y1 - v4*Power(x5,2)*y1 - 
     v4*Power(x1,2)*y2 - v5*Power(x1,2)*y2 - 3*v1*x1*x2*y2 + v4*x1*x2*y2 + v5*x1*x2*y2 + v1*x1*x3*y2 + v1*x2*x3*y2 + v4*x2*x3*y2 + v5*x2*x3*y2 - v1*Power(x3,2)*y2 - v4*Power(x3,2)*y2 - v5*Power(x3,2)*y2 + v1*x1*x4*y2 + v4*x1*x4*y2 + v1*x2*x4*y2 - 
     3*v4*x2*x4*y2 + v5*x2*x4*y2 + v4*x3*x4*y2 - v1*Power(x4,2)*y2 - v5*Power(x4,2)*y2 + v1*x1*x5*y2 + v5*x1*x5*y2 + v1*x2*x5*y2 + v4*x2*x5*y2 - 3*v5*x2*x5*y2 + v5*x3*x5*y2 + v4*x4*x5*y2 + v5*x4*x5*y2 - v1*Power(x5,2)*y2 - v4*Power(x5,2)*y2 - 
     v4*Power(x1,2)*y3 - v5*Power(x1,2)*y3 + v1*x1*x2*y3 - v1*Power(x2,2)*y3 - v4*Power(x2,2)*y3 - v5*Power(x2,2)*y3 - 3*v1*x1*x3*y3 + v4*x1*x3*y3 + v5*x1*x3*y3 + v1*x2*x3*y3 + v4*x2*x3*y3 + v5*x2*x3*y3 + v1*x1*x4*y3 + v4*x1*x4*y3 + v4*x2*x4*y3 + 
     v1*x3*x4*y3 - 3*v4*x3*x4*y3 + v5*x3*x4*y3 - v1*Power(x4,2)*y3 - v5*Power(x4,2)*y3 + v1*x1*x5*y3 + v5*x1*x5*y3 + v5*x2*x5*y3 + v1*x3*x5*y3 + v4*x3*x5*y3 - 3*v5*x3*x5*y3 + v4*x4*x5*y3 + v5*x4*x5*y3 - v1*Power(x5,2)*y3 - v4*Power(x5,2)*y3 + 
     3*v4*Power(x1,2)*y4 - v5*Power(x1,2)*y4 + v1*x1*x2*y4 - 2*v4*x1*x2*y4 - v1*Power(x2,2)*y4 + 3*v4*Power(x2,2)*y4 - v5*Power(x2,2)*y4 + v1*x1*x3*y4 - 2*v4*x1*x3*y4 - 2*v4*x2*x3*y4 - v1*Power(x3,2)*y4 + 3*v4*Power(x3,2)*y4 - v5*Power(x3,2)*y4 - 
     3*v1*x1*x4*y4 + v5*x1*x4*y4 + v1*x2*x4*y4 + v5*x2*x4*y4 + v1*x3*x4*y4 + v5*x3*x4*y4 + v1*x1*x5*y4 - 2*v4*x1*x5*y4 + v5*x1*x5*y4 - 2*v4*x2*x5*y4 + v5*x2*x5*y4 - 2*v4*x3*x5*y4 + v5*x3*x5*y4 + v1*x4*x5*y4 - 3*v5*x4*x5*y4 - v1*Power(x5,2)*y4 + 
     3*v4*Power(x5,2)*y4 - v4*Power(x1,2)*y5 + 3*v5*Power(x1,2)*y5 + v1*x1*x2*y5 - 2*v5*x1*x2*y5 - v1*Power(x2,2)*y5 - v4*Power(x2,2)*y5 + 3*v5*Power(x2,2)*y5 + v1*x1*x3*y5 - 2*v5*x1*x3*y5 - 2*v5*x2*x3*y5 - v1*Power(x3,2)*y5 - v4*Power(x3,2)*y5 + 
     3*v5*Power(x3,2)*y5 + v1*x1*x4*y5 + v4*x1*x4*y5 - 2*v5*x1*x4*y5 + v4*x2*x4*y5 - 2*v5*x2*x4*y5 + v4*x3*x4*y5 - 2*v5*x3*x4*y5 - v1*Power(x4,2)*y5 + 3*v5*Power(x4,2)*y5 - 3*v1*x1*x5*y5 + v4*x1*x5*y5 + v1*x2*x5*y5 + v4*x2*x5*y5 + v1*x3*x5*y5 + 
     v4*x3*x5*y5 + v1*x4*x5*y5 - 3*v4*x4*x5*y5 + v3*(x3*x4*y1 - Power(x4,2)*y1 + x3*x5*y1 - Power(x5,2)*y1 + x3*x4*y2 - Power(x4,2)*y2 + x3*x5*y2 - Power(x5,2)*y2 + 3*Power(x4,2)*y3 - 2*x4*x5*y3 + 3*Power(x5,2)*y3 - 3*x3*x4*y4 + x3*x5*y4 + x4*x5*y4 - 
        Power(x5,2)*y4 + x3*x4*y5 - Power(x4,2)*y5 - 3*x3*x5*y5 + x4*x5*y5 - Power(x2,2)*(y1 - 3*y3 + y4 + y5) - Power(x1,2)*(y2 - 3*y3 + y4 + y5) + x2*(x4*(y2 - 2*y3 + y4) + x5*(y2 - 2*y3 + y5) + x3*(y1 - 3*y2 + y4 + y5)) + 
        x1*(x4*y1 + x5*y1 + x2*(y1 + y2 - 2*y3) - 2*x4*y3 - 2*x5*y3 + x4*y4 + x5*y5 + x3*(-3*y1 + y2 + y4 + y5))) + 
     v2*(-(Power(x3,2)*y1) - Power(x4,2)*y1 - Power(x5,2)*y1 + 3*Power(x3,2)*y2 - 2*x3*x4*y2 + 3*Power(x4,2)*y2 - 2*x3*x5*y2 - 2*x4*x5*y2 + 3*Power(x5,2)*y2 + x3*x4*y3 - Power(x4,2)*y3 + x3*x5*y3 - Power(x5,2)*y3 - Power(x3,2)*y4 + x3*x4*y4 + x4*x5*y4 - 
        Power(x5,2)*y4 + Power(x1,2)*(3*y2 - y3 - y4 - y5) - Power(x3,2)*y5 - Power(x4,2)*y5 + x3*x5*y5 + x4*x5*y5 + x2*(x5*(y1 + y3 + y4 - 3*y5) + x4*(y1 + y3 - 3*y4 + y5) + x3*(y1 - 3*y3 + y4 + y5)) + 
        x1*(x4*y1 + x5*y1 - 2*x4*y2 - 2*x5*y2 + x3*(y1 - 2*y2 + y3) + x4*y4 + x5*y5 + x2*(-3*y1 + y3 + y4 + y5))))/
   (3*Power(x4,2)*Power(y1,2) - 2*x4*x5*Power(y1,2) + 3*Power(x5,2)*Power(y1,2) + 2*x1*x4*y1*y2 - 2*Power(x4,2)*y1*y2 + 2*x1*x5*y1*y2 - 2*Power(x5,2)*y1*y2 + 3*Power(x1,2)*Power(y2,2) - 2*x1*x4*Power(y2,2) + 3*Power(x4,2)*Power(y2,2) - 
     2*x1*x5*Power(y2,2) - 2*x4*x5*Power(y2,2) + 3*Power(x5,2)*Power(y2,2) + 2*x1*x4*y1*y3 - 2*Power(x4,2)*y1*y3 + 2*x1*x5*y1*y3 - 2*Power(x5,2)*y1*y3 - 2*Power(x1,2)*y2*y3 - 2*Power(x4,2)*y2*y3 - 2*Power(x5,2)*y2*y3 + 3*Power(x1,2)*Power(y3,2) - 
     2*x1*x4*Power(y3,2) + 3*Power(x4,2)*Power(y3,2) - 2*x1*x5*Power(y3,2) - 2*x4*x5*Power(y3,2) + 3*Power(x5,2)*Power(y3,2) - 6*x1*x4*y1*y4 + 2*x1*x5*y1*y4 + 2*x4*x5*y1*y4 - 2*Power(x5,2)*y1*y4 - 2*Power(x1,2)*y2*y4 + 2*x1*x4*y2*y4 + 2*x4*x5*y2*y4 - 
     2*Power(x5,2)*y2*y4 - 2*Power(x1,2)*y3*y4 + 2*x1*x4*y3*y4 + 2*x4*x5*y3*y4 - 2*Power(x5,2)*y3*y4 + 3*Power(x1,2)*Power(y4,2) - 2*x1*x5*Power(y4,2) + 3*Power(x5,2)*Power(y4,2) + 2*x1*x4*y1*y5 - 2*Power(x4,2)*y1*y5 - 6*x1*x5*y1*y5 + 2*x4*x5*y1*y5 - 
     2*Power(x1,2)*y2*y5 - 2*Power(x4,2)*y2*y5 + 2*x1*x5*y2*y5 + 2*x4*x5*y2*y5 - 2*Power(x1,2)*y3*y5 - 2*Power(x4,2)*y3*y5 + 2*x1*x5*y3*y5 + 2*x4*x5*y3*y5 - 2*Power(x1,2)*y4*y5 + 2*x1*x4*y4*y5 + 2*x1*x5*y4*y5 - 6*x4*x5*y4*y5 + 3*Power(x1,2)*Power(y5,2) - 
     2*x1*x4*Power(y5,2) + 3*Power(x4,2)*Power(y5,2) + Power(x3,2)*(3*Power(y1,2) + 3*Power(y2,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y2*(y4 + y5) - 2*y1*(y2 + y4 + y5)) + 
     Power(x2,2)*(3*Power(y1,2) + 3*Power(y3,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y3*(y4 + y5) - 2*y1*(y3 + y4 + y5)) - 
     2*x2*(x5*Power(y1,2) + 3*x1*y1*y2 - x5*y1*y2 - x1*y1*y3 - x1*y2*y3 - x5*y2*y3 + x1*Power(y3,2) + x5*Power(y3,2) - x1*y1*y4 - x1*y2*y4 - x5*y2*y4 + x1*Power(y4,2) + x5*Power(y4,2) - x1*y1*y5 - x5*y1*y5 - x1*y2*y5 + 3*x5*y2*y5 - x5*y3*y5 - x5*y4*y5 + 
        x1*Power(y5,2) + x3*(Power(y1,2) - y1*(y2 + y3) - y3*y4 + Power(y4,2) + y2*(3*y3 - y4 - y5) - y3*y5 + Power(y5,2)) + x4*(Power(y1,2) + Power(y3,2) - y3*y4 - y1*(y2 + y4) - y4*y5 + Power(y5,2) - y2*(y3 - 3*y4 + y5))) - 
     2*x3*(x4*(Power(y1,2) + Power(y2,2) + 3*y3*y4 - y1*(y3 + y4) - y2*(y3 + y4) - y3*y5 - y4*y5 + Power(y5,2)) + x5*(Power(y1,2) + Power(y2,2) - y3*y4 + Power(y4,2) + 3*y3*y5 - y4*y5 - y1*(y3 + y5) - y2*(y3 + y5)) - 
        x1*(-Power(y2,2) + y2*y3 + y3*y4 - Power(y4,2) + y3*y5 - Power(y5,2) + y1*(y2 - 3*y3 + y4 + y5))));
M[3][1] = (u5*Power(x2,2)*Power(y1,2) - u2*x2*x3*Power(y1,2) + u2*Power(x3,2)*Power(y1,2) + u5*Power(x3,2)*Power(y1,2) - u2*x2*x4*Power(y1,2) + u2*Power(x4,2)*Power(y1,2) + u5*Power(x4,2)*Power(y1,2) - u2*x2*x5*Power(y1,2) - u5*x2*x5*Power(y1,2) - 
     u5*x3*x5*Power(y1,2) - u5*x4*x5*Power(y1,2) + u2*Power(x5,2)*Power(y1,2) - 2*u5*x1*x2*y1*y2 + u2*x1*x3*y1*y2 + u1*x2*x3*y1*y2 - u1*Power(x3,2)*y1*y2 - u2*Power(x3,2)*y1*y2 + u2*x1*x4*y1*y2 + u1*x2*x4*y1*y2 - u1*Power(x4,2)*y1*y2 - 
     u2*Power(x4,2)*y1*y2 + u2*x1*x5*y1*y2 + u5*x1*x5*y1*y2 + u1*x2*x5*y1*y2 + u5*x2*x5*y1*y2 - u1*Power(x5,2)*y1*y2 - u2*Power(x5,2)*y1*y2 + u5*Power(x1,2)*Power(y2,2) - u1*x1*x3*Power(y2,2) + u1*Power(x3,2)*Power(y2,2) + u5*Power(x3,2)*Power(y2,2) - 
     u1*x1*x4*Power(y2,2) + u1*Power(x4,2)*Power(y2,2) + u5*Power(x4,2)*Power(y2,2) - u1*x1*x5*Power(y2,2) - u5*x1*x5*Power(y2,2) - u5*x3*x5*Power(y2,2) - u5*x4*x5*Power(y2,2) + u1*Power(x5,2)*Power(y2,2) + u2*x1*x2*y1*y3 - u1*Power(x2,2)*y1*y3 - 
     2*u2*x1*x3*y1*y3 - 2*u5*x1*x3*y1*y3 + u1*x2*x3*y1*y3 + u2*x2*x3*y1*y3 + u1*x3*x4*y1*y3 - u1*Power(x4,2)*y1*y3 + u5*x1*x5*y1*y3 + u1*x3*x5*y1*y3 + u5*x3*x5*y1*y3 - u1*Power(x5,2)*y1*y3 - u2*Power(x1,2)*y2*y3 + u1*x1*x2*y2*y3 + u1*x1*x3*y2*y3 + 
     u2*x1*x3*y2*y3 - 2*u1*x2*x3*y2*y3 - 2*u5*x2*x3*y2*y3 + u2*x3*x4*y2*y3 - u2*Power(x4,2)*y2*y3 + u5*x2*x5*y2*y3 + u2*x3*x5*y2*y3 + u5*x3*x5*y2*y3 - u2*Power(x5,2)*y2*y3 + u2*Power(x1,2)*Power(y3,2) + u5*Power(x1,2)*Power(y3,2) - u1*x1*x2*Power(y3,2) - 
     u2*x1*x2*Power(y3,2) + u1*Power(x2,2)*Power(y3,2) + u5*Power(x2,2)*Power(y3,2) - u1*x1*x4*Power(y3,2) - u2*x2*x4*Power(y3,2) + u1*Power(x4,2)*Power(y3,2) + u2*Power(x4,2)*Power(y3,2) + u5*Power(x4,2)*Power(y3,2) - u1*x1*x5*Power(y3,2) - 
     u5*x1*x5*Power(y3,2) - u2*x2*x5*Power(y3,2) - u5*x2*x5*Power(y3,2) - u5*x4*x5*Power(y3,2) + u1*Power(x5,2)*Power(y3,2) + u2*Power(x5,2)*Power(y3,2) + u2*x1*x2*y1*y4 - u1*Power(x2,2)*y1*y4 - u1*Power(x3,2)*y1*y4 - 2*u2*x1*x4*y1*y4 - 2*u5*x1*x4*y1*y4 + 
     u1*x2*x4*y1*y4 + u2*x2*x4*y1*y4 + u1*x3*x4*y1*y4 + u5*x1*x5*y1*y4 + u1*x4*x5*y1*y4 + u5*x4*x5*y1*y4 - u1*Power(x5,2)*y1*y4 - u2*Power(x1,2)*y2*y4 + u1*x1*x2*y2*y4 - u2*Power(x3,2)*y2*y4 + u1*x1*x4*y2*y4 + u2*x1*x4*y2*y4 - 2*u1*x2*x4*y2*y4 - 
     2*u5*x2*x4*y2*y4 + u2*x3*x4*y2*y4 + u5*x2*x5*y2*y4 + u2*x4*x5*y2*y4 + u5*x4*x5*y2*y4 - u2*Power(x5,2)*y2*y4 + u1*x1*x3*y3*y4 + u2*x2*x3*y3*y4 + u1*x1*x4*y3*y4 + u2*x2*x4*y3*y4 - 2*u1*x3*x4*y3*y4 - 2*u2*x3*x4*y3*y4 - 2*u5*x3*x4*y3*y4 + u5*x3*x5*y3*y4 + 
     u5*x4*x5*y3*y4 + u2*Power(x1,2)*Power(y4,2) + u5*Power(x1,2)*Power(y4,2) - u1*x1*x2*Power(y4,2) - u2*x1*x2*Power(y4,2) + u1*Power(x2,2)*Power(y4,2) + u5*Power(x2,2)*Power(y4,2) - u1*x1*x3*Power(y4,2) - u2*x2*x3*Power(y4,2) + 
     u1*Power(x3,2)*Power(y4,2) + u2*Power(x3,2)*Power(y4,2) + u5*Power(x3,2)*Power(y4,2) - u1*x1*x5*Power(y4,2) - u5*x1*x5*Power(y4,2) - u2*x2*x5*Power(y4,2) - u5*x2*x5*Power(y4,2) - u5*x3*x5*Power(y4,2) + u1*Power(x5,2)*Power(y4,2) + 
     u2*Power(x5,2)*Power(y4,2) + u2*x1*x2*y1*y5 + u5*x1*x2*y1*y5 - u1*Power(x2,2)*y1*y5 - u5*Power(x2,2)*y1*y5 + u5*x1*x3*y1*y5 - u1*Power(x3,2)*y1*y5 - u5*Power(x3,2)*y1*y5 + u5*x1*x4*y1*y5 - u1*Power(x4,2)*y1*y5 - u5*Power(x4,2)*y1*y5 - 
     2*u2*x1*x5*y1*y5 + u1*x2*x5*y1*y5 + u2*x2*x5*y1*y5 + u1*x3*x5*y1*y5 + u1*x4*x5*y1*y5 - u2*Power(x1,2)*y2*y5 - u5*Power(x1,2)*y2*y5 + u1*x1*x2*y2*y5 + u5*x1*x2*y2*y5 + u5*x2*x3*y2*y5 - u2*Power(x3,2)*y2*y5 - u5*Power(x3,2)*y2*y5 + u5*x2*x4*y2*y5 - 
     u2*Power(x4,2)*y2*y5 - u5*Power(x4,2)*y2*y5 + u1*x1*x5*y2*y5 + u2*x1*x5*y2*y5 - 2*u1*x2*x5*y2*y5 + u2*x3*x5*y2*y5 + u2*x4*x5*y2*y5 - u5*Power(x1,2)*y3*y5 - u5*Power(x2,2)*y3*y5 + u1*x1*x3*y3*y5 + u5*x1*x3*y3*y5 + u2*x2*x3*y3*y5 + u5*x2*x3*y3*y5 + 
     u5*x3*x4*y3*y5 - u5*Power(x4,2)*y3*y5 + u1*x1*x5*y3*y5 + u2*x2*x5*y3*y5 - 2*u1*x3*x5*y3*y5 - 2*u2*x3*x5*y3*y5 - u5*Power(x1,2)*y4*y5 - u5*Power(x2,2)*y4*y5 - u5*Power(x3,2)*y4*y5 + u1*x1*x4*y4*y5 + u5*x1*x4*y4*y5 + u2*x2*x4*y4*y5 + u5*x2*x4*y4*y5 + 
     u5*x3*x4*y4*y5 + u1*x1*x5*y4*y5 + u2*x2*x5*y4*y5 - 2*u1*x4*x5*y4*y5 - 2*u2*x4*x5*y4*y5 + u2*Power(x1,2)*Power(y5,2) - u1*x1*x2*Power(y5,2) - u2*x1*x2*Power(y5,2) + u1*Power(x2,2)*Power(y5,2) - u1*x1*x3*Power(y5,2) - u2*x2*x3*Power(y5,2) + 
     u1*Power(x3,2)*Power(y5,2) + u2*Power(x3,2)*Power(y5,2) - u1*x1*x4*Power(y5,2) - u2*x2*x4*Power(y5,2) + u1*Power(x4,2)*Power(y5,2) + u2*Power(x4,2)*Power(y5,2) + 
     u4*(-(x4*x5*Power(y1,2)) + Power(x5,2)*Power(y1,2) + x1*x4*y1*y2 + Power(x1,2)*Power(y2,2) - x1*x4*Power(y2,2) - x4*x5*Power(y2,2) + Power(x5,2)*Power(y2,2) + x1*x4*y1*y3 + Power(x1,2)*Power(y3,2) - x1*x4*Power(y3,2) - x4*x5*Power(y3,2) + 
        Power(x5,2)*Power(y3,2) + x1*x5*y1*y4 - Power(x5,2)*y1*y4 - Power(x1,2)*y2*y4 - Power(x5,2)*y2*y4 - Power(x1,2)*y3*y4 - Power(x5,2)*y3*y4 + x1*x4*y1*y5 - 2*x1*x5*y1*y5 + x4*x5*y1*y5 + x4*x5*y2*y5 + x4*x5*y3*y5 - Power(x1,2)*y4*y5 + x1*x5*y4*y5 + 
        Power(x1,2)*Power(y5,2) - x1*x4*Power(y5,2) + Power(x3,2)*(Power(y1,2) + Power(y2,2) - y1*y4 - y2*y4 + y5*(-y4 + y5)) + Power(x2,2)*(Power(y1,2) + Power(y3,2) - y1*y4 - y3*y4 + y5*(-y4 + y5)) + 
        x3*(x1*(-2*y1*y3 + y1*y4 + y3*y4) + x5*(y3*y4 - 2*y3*y5 + y4*y5) - x4*(Power(y1,2) + Power(y2,2) - y1*y3 - y2*y3 - y3*y5 + Power(y5,2))) + 
        x2*(-2*x1*y1*y2 - 2*x3*y2*y3 + x1*y1*y4 + x1*y2*y4 + x3*y2*y4 + x5*y2*y4 + x3*y3*y4 - 2*x5*y2*y5 + x5*y4*y5 - x4*(Power(y1,2) - y1*y2 + Power(y3,2) + Power(y5,2) - y2*(y3 + y5)))) + 
     u3*(Power(x4,2)*Power(y1,2) + Power(x5,2)*Power(y1,2) + Power(x1,2)*Power(y2,2) + Power(x4,2)*Power(y2,2) + Power(x5,2)*Power(y2,2) + x1*x4*y1*y3 - Power(x4,2)*y1*y3 + x1*x5*y1*y3 - Power(x5,2)*y1*y3 - Power(x1,2)*y2*y3 - Power(x4,2)*y2*y3 - 
        Power(x5,2)*y2*y3 - 2*x1*x4*y1*y4 - Power(x1,2)*y3*y4 + x1*x4*y3*y4 + x4*x5*y3*y4 - Power(x5,2)*y3*y4 + Power(x1,2)*Power(y4,2) + Power(x5,2)*Power(y4,2) - 2*x1*x5*y1*y5 - Power(x1,2)*y3*y5 - Power(x4,2)*y3*y5 + x1*x5*y3*y5 + x4*x5*y3*y5 - 
        2*x4*x5*y4*y5 + Power(x1,2)*Power(y5,2) + Power(x4,2)*Power(y5,2) + Power(x2,2)*(Power(y1,2) - y1*y3 + Power(y4,2) + Power(y5,2) - y3*(y4 + y5)) + 
        x2*(-2*x1*y1*y2 + x1*y1*y3 + x1*y2*y3 + x4*y2*y3 + x5*y2*y3 - 2*x4*y2*y4 + x4*y3*y4 - 2*x5*y2*y5 + x5*y3*y5 - x3*(Power(y1,2) - y1*y2 + Power(y4,2) + Power(y5,2) - y2*(y4 + y5))) + 
        x3*(-(x5*(Power(y1,2) + Power(y2,2) + Power(y4,2) - y1*y5 - y2*y5 - y4*y5)) - x4*(Power(y1,2) + Power(y2,2) - y1*y4 - y2*y4 - y4*y5 + Power(y5,2)) + x1*(-Power(y2,2) - Power(y4,2) - Power(y5,2) + y1*(y2 + y4 + y5)))))/
   (3*Power(x4,2)*Power(y1,2) - 2*x4*x5*Power(y1,2) + 3*Power(x5,2)*Power(y1,2) + 2*x1*x4*y1*y2 - 2*Power(x4,2)*y1*y2 + 2*x1*x5*y1*y2 - 2*Power(x5,2)*y1*y2 + 3*Power(x1,2)*Power(y2,2) - 2*x1*x4*Power(y2,2) + 3*Power(x4,2)*Power(y2,2) - 
     2*x1*x5*Power(y2,2) - 2*x4*x5*Power(y2,2) + 3*Power(x5,2)*Power(y2,2) + 2*x1*x4*y1*y3 - 2*Power(x4,2)*y1*y3 + 2*x1*x5*y1*y3 - 2*Power(x5,2)*y1*y3 - 2*Power(x1,2)*y2*y3 - 2*Power(x4,2)*y2*y3 - 2*Power(x5,2)*y2*y3 + 3*Power(x1,2)*Power(y3,2) - 
     2*x1*x4*Power(y3,2) + 3*Power(x4,2)*Power(y3,2) - 2*x1*x5*Power(y3,2) - 2*x4*x5*Power(y3,2) + 3*Power(x5,2)*Power(y3,2) - 6*x1*x4*y1*y4 + 2*x1*x5*y1*y4 + 2*x4*x5*y1*y4 - 2*Power(x5,2)*y1*y4 - 2*Power(x1,2)*y2*y4 + 2*x1*x4*y2*y4 + 2*x4*x5*y2*y4 - 
     2*Power(x5,2)*y2*y4 - 2*Power(x1,2)*y3*y4 + 2*x1*x4*y3*y4 + 2*x4*x5*y3*y4 - 2*Power(x5,2)*y3*y4 + 3*Power(x1,2)*Power(y4,2) - 2*x1*x5*Power(y4,2) + 3*Power(x5,2)*Power(y4,2) + 2*x1*x4*y1*y5 - 2*Power(x4,2)*y1*y5 - 6*x1*x5*y1*y5 + 2*x4*x5*y1*y5 - 
     2*Power(x1,2)*y2*y5 - 2*Power(x4,2)*y2*y5 + 2*x1*x5*y2*y5 + 2*x4*x5*y2*y5 - 2*Power(x1,2)*y3*y5 - 2*Power(x4,2)*y3*y5 + 2*x1*x5*y3*y5 + 2*x4*x5*y3*y5 - 2*Power(x1,2)*y4*y5 + 2*x1*x4*y4*y5 + 2*x1*x5*y4*y5 - 6*x4*x5*y4*y5 + 3*Power(x1,2)*Power(y5,2) - 
     2*x1*x4*Power(y5,2) + 3*Power(x4,2)*Power(y5,2) + Power(x3,2)*(3*Power(y1,2) + 3*Power(y2,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y2*(y4 + y5) - 2*y1*(y2 + y4 + y5)) + 
     Power(x2,2)*(3*Power(y1,2) + 3*Power(y3,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y3*(y4 + y5) - 2*y1*(y3 + y4 + y5)) - 
     2*x2*(x5*Power(y1,2) + 3*x1*y1*y2 - x5*y1*y2 - x1*y1*y3 - x1*y2*y3 - x5*y2*y3 + x1*Power(y3,2) + x5*Power(y3,2) - x1*y1*y4 - x1*y2*y4 - x5*y2*y4 + x1*Power(y4,2) + x5*Power(y4,2) - x1*y1*y5 - x5*y1*y5 - x1*y2*y5 + 3*x5*y2*y5 - x5*y3*y5 - x5*y4*y5 + 
        x1*Power(y5,2) + x3*(Power(y1,2) - y1*(y2 + y3) - y3*y4 + Power(y4,2) + y2*(3*y3 - y4 - y5) - y3*y5 + Power(y5,2)) + x4*(Power(y1,2) + Power(y3,2) - y3*y4 - y1*(y2 + y4) - y4*y5 + Power(y5,2) - y2*(y3 - 3*y4 + y5))) - 
     2*x3*(x4*(Power(y1,2) + Power(y2,2) + 3*y3*y4 - y1*(y3 + y4) - y2*(y3 + y4) - y3*y5 - y4*y5 + Power(y5,2)) + x5*(Power(y1,2) + Power(y2,2) - y3*y4 + Power(y4,2) + 3*y3*y5 - y4*y5 - y1*(y3 + y5) - y2*(y3 + y5)) - 
        x1*(-Power(y2,2) + y2*y3 + y3*y4 - Power(y4,2) + y3*y5 - Power(y5,2) + y1*(y2 - 3*y3 + y4 + y5))));
M[3][2] = (v5*Power(x2,2)*Power(y1,2) - v2*x2*x3*Power(y1,2) + v2*Power(x3,2)*Power(y1,2) + v5*Power(x3,2)*Power(y1,2) - v2*x2*x4*Power(y1,2) + v2*Power(x4,2)*Power(y1,2) + v5*Power(x4,2)*Power(y1,2) - v2*x2*x5*Power(y1,2) - v5*x2*x5*Power(y1,2) - 
     v5*x3*x5*Power(y1,2) - v5*x4*x5*Power(y1,2) + v2*Power(x5,2)*Power(y1,2) - 2*v5*x1*x2*y1*y2 + v2*x1*x3*y1*y2 + v1*x2*x3*y1*y2 - v1*Power(x3,2)*y1*y2 - v2*Power(x3,2)*y1*y2 + v2*x1*x4*y1*y2 + v1*x2*x4*y1*y2 - v1*Power(x4,2)*y1*y2 - 
     v2*Power(x4,2)*y1*y2 + v2*x1*x5*y1*y2 + v5*x1*x5*y1*y2 + v1*x2*x5*y1*y2 + v5*x2*x5*y1*y2 - v1*Power(x5,2)*y1*y2 - v2*Power(x5,2)*y1*y2 + v5*Power(x1,2)*Power(y2,2) - v1*x1*x3*Power(y2,2) + v1*Power(x3,2)*Power(y2,2) + v5*Power(x3,2)*Power(y2,2) - 
     v1*x1*x4*Power(y2,2) + v1*Power(x4,2)*Power(y2,2) + v5*Power(x4,2)*Power(y2,2) - v1*x1*x5*Power(y2,2) - v5*x1*x5*Power(y2,2) - v5*x3*x5*Power(y2,2) - v5*x4*x5*Power(y2,2) + v1*Power(x5,2)*Power(y2,2) + v2*x1*x2*y1*y3 - v1*Power(x2,2)*y1*y3 - 
     2*v2*x1*x3*y1*y3 - 2*v5*x1*x3*y1*y3 + v1*x2*x3*y1*y3 + v2*x2*x3*y1*y3 + v1*x3*x4*y1*y3 - v1*Power(x4,2)*y1*y3 + v5*x1*x5*y1*y3 + v1*x3*x5*y1*y3 + v5*x3*x5*y1*y3 - v1*Power(x5,2)*y1*y3 - v2*Power(x1,2)*y2*y3 + v1*x1*x2*y2*y3 + v1*x1*x3*y2*y3 + 
     v2*x1*x3*y2*y3 - 2*v1*x2*x3*y2*y3 - 2*v5*x2*x3*y2*y3 + v2*x3*x4*y2*y3 - v2*Power(x4,2)*y2*y3 + v5*x2*x5*y2*y3 + v2*x3*x5*y2*y3 + v5*x3*x5*y2*y3 - v2*Power(x5,2)*y2*y3 + v2*Power(x1,2)*Power(y3,2) + v5*Power(x1,2)*Power(y3,2) - v1*x1*x2*Power(y3,2) - 
     v2*x1*x2*Power(y3,2) + v1*Power(x2,2)*Power(y3,2) + v5*Power(x2,2)*Power(y3,2) - v1*x1*x4*Power(y3,2) - v2*x2*x4*Power(y3,2) + v1*Power(x4,2)*Power(y3,2) + v2*Power(x4,2)*Power(y3,2) + v5*Power(x4,2)*Power(y3,2) - v1*x1*x5*Power(y3,2) - 
     v5*x1*x5*Power(y3,2) - v2*x2*x5*Power(y3,2) - v5*x2*x5*Power(y3,2) - v5*x4*x5*Power(y3,2) + v1*Power(x5,2)*Power(y3,2) + v2*Power(x5,2)*Power(y3,2) + v2*x1*x2*y1*y4 - v1*Power(x2,2)*y1*y4 - v1*Power(x3,2)*y1*y4 - 2*v2*x1*x4*y1*y4 - 2*v5*x1*x4*y1*y4 + 
     v1*x2*x4*y1*y4 + v2*x2*x4*y1*y4 + v1*x3*x4*y1*y4 + v5*x1*x5*y1*y4 + v1*x4*x5*y1*y4 + v5*x4*x5*y1*y4 - v1*Power(x5,2)*y1*y4 - v2*Power(x1,2)*y2*y4 + v1*x1*x2*y2*y4 - v2*Power(x3,2)*y2*y4 + v1*x1*x4*y2*y4 + v2*x1*x4*y2*y4 - 2*v1*x2*x4*y2*y4 - 
     2*v5*x2*x4*y2*y4 + v2*x3*x4*y2*y4 + v5*x2*x5*y2*y4 + v2*x4*x5*y2*y4 + v5*x4*x5*y2*y4 - v2*Power(x5,2)*y2*y4 + v1*x1*x3*y3*y4 + v2*x2*x3*y3*y4 + v1*x1*x4*y3*y4 + v2*x2*x4*y3*y4 - 2*v1*x3*x4*y3*y4 - 2*v2*x3*x4*y3*y4 - 2*v5*x3*x4*y3*y4 + v5*x3*x5*y3*y4 + 
     v5*x4*x5*y3*y4 + v2*Power(x1,2)*Power(y4,2) + v5*Power(x1,2)*Power(y4,2) - v1*x1*x2*Power(y4,2) - v2*x1*x2*Power(y4,2) + v1*Power(x2,2)*Power(y4,2) + v5*Power(x2,2)*Power(y4,2) - v1*x1*x3*Power(y4,2) - v2*x2*x3*Power(y4,2) + 
     v1*Power(x3,2)*Power(y4,2) + v2*Power(x3,2)*Power(y4,2) + v5*Power(x3,2)*Power(y4,2) - v1*x1*x5*Power(y4,2) - v5*x1*x5*Power(y4,2) - v2*x2*x5*Power(y4,2) - v5*x2*x5*Power(y4,2) - v5*x3*x5*Power(y4,2) + v1*Power(x5,2)*Power(y4,2) + 
     v2*Power(x5,2)*Power(y4,2) + v2*x1*x2*y1*y5 + v5*x1*x2*y1*y5 - v1*Power(x2,2)*y1*y5 - v5*Power(x2,2)*y1*y5 + v5*x1*x3*y1*y5 - v1*Power(x3,2)*y1*y5 - v5*Power(x3,2)*y1*y5 + v5*x1*x4*y1*y5 - v1*Power(x4,2)*y1*y5 - v5*Power(x4,2)*y1*y5 - 
     2*v2*x1*x5*y1*y5 + v1*x2*x5*y1*y5 + v2*x2*x5*y1*y5 + v1*x3*x5*y1*y5 + v1*x4*x5*y1*y5 - v2*Power(x1,2)*y2*y5 - v5*Power(x1,2)*y2*y5 + v1*x1*x2*y2*y5 + v5*x1*x2*y2*y5 + v5*x2*x3*y2*y5 - v2*Power(x3,2)*y2*y5 - v5*Power(x3,2)*y2*y5 + v5*x2*x4*y2*y5 - 
     v2*Power(x4,2)*y2*y5 - v5*Power(x4,2)*y2*y5 + v1*x1*x5*y2*y5 + v2*x1*x5*y2*y5 - 2*v1*x2*x5*y2*y5 + v2*x3*x5*y2*y5 + v2*x4*x5*y2*y5 - v5*Power(x1,2)*y3*y5 - v5*Power(x2,2)*y3*y5 + v1*x1*x3*y3*y5 + v5*x1*x3*y3*y5 + v2*x2*x3*y3*y5 + v5*x2*x3*y3*y5 + 
     v5*x3*x4*y3*y5 - v5*Power(x4,2)*y3*y5 + v1*x1*x5*y3*y5 + v2*x2*x5*y3*y5 - 2*v1*x3*x5*y3*y5 - 2*v2*x3*x5*y3*y5 - v5*Power(x1,2)*y4*y5 - v5*Power(x2,2)*y4*y5 - v5*Power(x3,2)*y4*y5 + v1*x1*x4*y4*y5 + v5*x1*x4*y4*y5 + v2*x2*x4*y4*y5 + v5*x2*x4*y4*y5 + 
     v5*x3*x4*y4*y5 + v1*x1*x5*y4*y5 + v2*x2*x5*y4*y5 - 2*v1*x4*x5*y4*y5 - 2*v2*x4*x5*y4*y5 + v2*Power(x1,2)*Power(y5,2) - v1*x1*x2*Power(y5,2) - v2*x1*x2*Power(y5,2) + v1*Power(x2,2)*Power(y5,2) - v1*x1*x3*Power(y5,2) - v2*x2*x3*Power(y5,2) + 
     v1*Power(x3,2)*Power(y5,2) + v2*Power(x3,2)*Power(y5,2) - v1*x1*x4*Power(y5,2) - v2*x2*x4*Power(y5,2) + v1*Power(x4,2)*Power(y5,2) + v2*Power(x4,2)*Power(y5,2) + 
     v4*(-(x4*x5*Power(y1,2)) + Power(x5,2)*Power(y1,2) + x1*x4*y1*y2 + Power(x1,2)*Power(y2,2) - x1*x4*Power(y2,2) - x4*x5*Power(y2,2) + Power(x5,2)*Power(y2,2) + x1*x4*y1*y3 + Power(x1,2)*Power(y3,2) - x1*x4*Power(y3,2) - x4*x5*Power(y3,2) + 
        Power(x5,2)*Power(y3,2) + x1*x5*y1*y4 - Power(x5,2)*y1*y4 - Power(x1,2)*y2*y4 - Power(x5,2)*y2*y4 - Power(x1,2)*y3*y4 - Power(x5,2)*y3*y4 + x1*x4*y1*y5 - 2*x1*x5*y1*y5 + x4*x5*y1*y5 + x4*x5*y2*y5 + x4*x5*y3*y5 - Power(x1,2)*y4*y5 + x1*x5*y4*y5 + 
        Power(x1,2)*Power(y5,2) - x1*x4*Power(y5,2) + Power(x3,2)*(Power(y1,2) + Power(y2,2) - y1*y4 - y2*y4 + y5*(-y4 + y5)) + Power(x2,2)*(Power(y1,2) + Power(y3,2) - y1*y4 - y3*y4 + y5*(-y4 + y5)) + 
        x3*(x1*(-2*y1*y3 + y1*y4 + y3*y4) + x5*(y3*y4 - 2*y3*y5 + y4*y5) - x4*(Power(y1,2) + Power(y2,2) - y1*y3 - y2*y3 - y3*y5 + Power(y5,2))) + 
        x2*(-2*x1*y1*y2 - 2*x3*y2*y3 + x1*y1*y4 + x1*y2*y4 + x3*y2*y4 + x5*y2*y4 + x3*y3*y4 - 2*x5*y2*y5 + x5*y4*y5 - x4*(Power(y1,2) - y1*y2 + Power(y3,2) + Power(y5,2) - y2*(y3 + y5)))) + 
     v3*(Power(x4,2)*Power(y1,2) + Power(x5,2)*Power(y1,2) + Power(x1,2)*Power(y2,2) + Power(x4,2)*Power(y2,2) + Power(x5,2)*Power(y2,2) + x1*x4*y1*y3 - Power(x4,2)*y1*y3 + x1*x5*y1*y3 - Power(x5,2)*y1*y3 - Power(x1,2)*y2*y3 - Power(x4,2)*y2*y3 - 
        Power(x5,2)*y2*y3 - 2*x1*x4*y1*y4 - Power(x1,2)*y3*y4 + x1*x4*y3*y4 + x4*x5*y3*y4 - Power(x5,2)*y3*y4 + Power(x1,2)*Power(y4,2) + Power(x5,2)*Power(y4,2) - 2*x1*x5*y1*y5 - Power(x1,2)*y3*y5 - Power(x4,2)*y3*y5 + x1*x5*y3*y5 + x4*x5*y3*y5 - 
        2*x4*x5*y4*y5 + Power(x1,2)*Power(y5,2) + Power(x4,2)*Power(y5,2) + Power(x2,2)*(Power(y1,2) - y1*y3 + Power(y4,2) + Power(y5,2) - y3*(y4 + y5)) + 
        x2*(-2*x1*y1*y2 + x1*y1*y3 + x1*y2*y3 + x4*y2*y3 + x5*y2*y3 - 2*x4*y2*y4 + x4*y3*y4 - 2*x5*y2*y5 + x5*y3*y5 - x3*(Power(y1,2) - y1*y2 + Power(y4,2) + Power(y5,2) - y2*(y4 + y5))) + 
        x3*(-(x5*(Power(y1,2) + Power(y2,2) + Power(y4,2) - y1*y5 - y2*y5 - y4*y5)) - x4*(Power(y1,2) + Power(y2,2) - y1*y4 - y2*y4 - y4*y5 + Power(y5,2)) + x1*(-Power(y2,2) - Power(y4,2) - Power(y5,2) + y1*(y2 + y4 + y5)))))/
   (3*Power(x4,2)*Power(y1,2) - 2*x4*x5*Power(y1,2) + 3*Power(x5,2)*Power(y1,2) + 2*x1*x4*y1*y2 - 2*Power(x4,2)*y1*y2 + 2*x1*x5*y1*y2 - 2*Power(x5,2)*y1*y2 + 3*Power(x1,2)*Power(y2,2) - 2*x1*x4*Power(y2,2) + 3*Power(x4,2)*Power(y2,2) - 
     2*x1*x5*Power(y2,2) - 2*x4*x5*Power(y2,2) + 3*Power(x5,2)*Power(y2,2) + 2*x1*x4*y1*y3 - 2*Power(x4,2)*y1*y3 + 2*x1*x5*y1*y3 - 2*Power(x5,2)*y1*y3 - 2*Power(x1,2)*y2*y3 - 2*Power(x4,2)*y2*y3 - 2*Power(x5,2)*y2*y3 + 3*Power(x1,2)*Power(y3,2) - 
     2*x1*x4*Power(y3,2) + 3*Power(x4,2)*Power(y3,2) - 2*x1*x5*Power(y3,2) - 2*x4*x5*Power(y3,2) + 3*Power(x5,2)*Power(y3,2) - 6*x1*x4*y1*y4 + 2*x1*x5*y1*y4 + 2*x4*x5*y1*y4 - 2*Power(x5,2)*y1*y4 - 2*Power(x1,2)*y2*y4 + 2*x1*x4*y2*y4 + 2*x4*x5*y2*y4 - 
     2*Power(x5,2)*y2*y4 - 2*Power(x1,2)*y3*y4 + 2*x1*x4*y3*y4 + 2*x4*x5*y3*y4 - 2*Power(x5,2)*y3*y4 + 3*Power(x1,2)*Power(y4,2) - 2*x1*x5*Power(y4,2) + 3*Power(x5,2)*Power(y4,2) + 2*x1*x4*y1*y5 - 2*Power(x4,2)*y1*y5 - 6*x1*x5*y1*y5 + 2*x4*x5*y1*y5 - 
     2*Power(x1,2)*y2*y5 - 2*Power(x4,2)*y2*y5 + 2*x1*x5*y2*y5 + 2*x4*x5*y2*y5 - 2*Power(x1,2)*y3*y5 - 2*Power(x4,2)*y3*y5 + 2*x1*x5*y3*y5 + 2*x4*x5*y3*y5 - 2*Power(x1,2)*y4*y5 + 2*x1*x4*y4*y5 + 2*x1*x5*y4*y5 - 6*x4*x5*y4*y5 + 3*Power(x1,2)*Power(y5,2) - 
     2*x1*x4*Power(y5,2) + 3*Power(x4,2)*Power(y5,2) + Power(x3,2)*(3*Power(y1,2) + 3*Power(y2,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y2*(y4 + y5) - 2*y1*(y2 + y4 + y5)) + 
     Power(x2,2)*(3*Power(y1,2) + 3*Power(y3,2) + 3*Power(y4,2) - 2*y4*y5 + 3*Power(y5,2) - 2*y3*(y4 + y5) - 2*y1*(y3 + y4 + y5)) - 
     2*x2*(x5*Power(y1,2) + 3*x1*y1*y2 - x5*y1*y2 - x1*y1*y3 - x1*y2*y3 - x5*y2*y3 + x1*Power(y3,2) + x5*Power(y3,2) - x1*y1*y4 - x1*y2*y4 - x5*y2*y4 + x1*Power(y4,2) + x5*Power(y4,2) - x1*y1*y5 - x5*y1*y5 - x1*y2*y5 + 3*x5*y2*y5 - x5*y3*y5 - x5*y4*y5 + 
        x1*Power(y5,2) + x3*(Power(y1,2) - y1*(y2 + y3) - y3*y4 + Power(y4,2) + y2*(3*y3 - y4 - y5) - y3*y5 + Power(y5,2)) + x4*(Power(y1,2) + Power(y3,2) - y3*y4 - y1*(y2 + y4) - y4*y5 + Power(y5,2) - y2*(y3 - 3*y4 + y5))) - 
     2*x3*(x4*(Power(y1,2) + Power(y2,2) + 3*y3*y4 - y1*(y3 + y4) - y2*(y3 + y4) - y3*y5 - y4*y5 + Power(y5,2)) + x5*(Power(y1,2) + Power(y2,2) - y3*y4 + Power(y4,2) + 3*y3*y5 - y4*y5 - y1*(y3 + y5) - y2*(y3 + y5)) - 
        x1*(-Power(y2,2) + y2*y3 + y3*y4 - Power(y4,2) + y3*y5 - Power(y5,2) + y1*(y2 - 3*y3 + y4 + y5))));
    int i, j;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
        {
            printf("M[%d][%d] = %f \n", i, j, M[i][j]);
        }
        
}