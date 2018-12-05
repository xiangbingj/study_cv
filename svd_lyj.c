#include <stdio.h>
#include <math.h>

void svd22(const double a[4], double u[4], double s[2], double v[4]) {
    s[0] = (sqrt(pow(a[0] - a[3], 2) + pow(a[1] + a[2], 2)) + sqrt(pow(a[0] + a[3], 2) + pow(a[1] - a[2], 2))) / 2;
    s[1] = fabs(s[0] - sqrt(pow(a[0] - a[3], 2) + pow(a[1] + a[2], 2)));
    v[2] = (s[0] > s[1]) ? sin((atan2(2 * (a[0] * a[1] + a[2] * a[3]), a[0] * a[0] - a[1] * a[1] + a[2] * a[2] - a[3] * a[3])) / 2) : 0;
    v[0] = sqrt(1 - v[2] * v[2]);
    v[1] = -v[2];
    v[3] = v[0];
    u[0] = (s[0] != 0) ? (a[0] * v[0] + a[1] * v[2]) / s[0] : 1;
    u[2] = (s[0] != 0) ? (a[2] * v[0] + a[3] * v[2]) / s[0] : 0;
    u[1] = (s[1] != 0) ? (a[0] * v[1] + a[1] * v[3]) / s[1] : -u[2];
    u[3] = (s[1] != 0) ? (a[2] * v[1] + a[3] * v[3]) / s[1] : u[0];
}

int main() {
    double a[4] = {267.22534, -48.82566, -184.26672, 289.1574}, u[4], s[2], v[4];
    svd22(a, u, s, v);
    printf("Matrix A:\n%f %f\n%f %f\n\n", a[0], a[1], a[2], a[3]);
    printf("Matrix U:\n%f %f\n%f %f\n\n", u[0], u[1], u[2], u[3]);
    printf("Matrix S:\n%f %f\n%f %f\n\n", s[0], 0, 0, s[1]);
    printf("Matrix V:\n%f %f\n%f %f\n\n", v[0], v[1], v[2], v[3]);
}