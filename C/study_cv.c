#include "study_cv.h"
#include <stdlib.h>

void svd22(const double a[4], double u[4], double s[2], double v[4]) {
    s[0] = (sqrt(pow(a[0] - a[3], 2) + pow(a[1] + a[2], 2)) + sqrt(pow(a[0] + a[3], 2) + pow(a[1] - a[2], 2))) / 2;
    s[1] = fabs(s[0] - sqrt(pow(a[0] - a[3], 2) + pow(a[1] + a[2], 2)));
    v[2] = (s[0] > s[1]) ? sin((atan2(2 * (a[0] * a[1] + a[2] * a[3]), a[0] * a[0] - a[1] * a[1] + a[2] * a[2] - a[3] * a[3])) / 2) : 0;
    v[0] = sqrt(1 - v[2] * v[2]);
    v[1] = -v[2];
    v[3] = v[0];
    u[0] = (s[0] != 0) ? -(a[0] * v[0] + a[1] * v[2]) / s[0] : 1;
    u[2] = (s[0] != 0) ? -(a[2] * v[0] + a[3] * v[2]) / s[0] : 0;
    u[1] = (s[1] != 0) ? (a[0] * v[1] + a[1] * v[3]) / s[1] : -u[2];
    u[3] = (s[1] != 0) ? (a[2] * v[1] + a[3] * v[3]) / s[1] : u[0];
    v[0] = -v[0];
    v[2] = -v[2];
}

#define SRC_NUM 5
#define SRC_DIM 2
double *study_umeyama(double *src, double *dst)
{
    int i, j, k;
    double src_mean[SRC_DIM] = { 0.0 };
    double dst_mean[SRC_DIM] = { 0.0 };
    for(i=0; i<SRC_NUM*2; i+=2)
    {
        src_mean[0] += src[i];
        src_mean[1] += src[i+1];
        dst_mean[0] += dst[i];
        dst_mean[1] += dst[i+1];
    }
    src_mean[0] /= SRC_NUM;
    src_mean[1] /= SRC_NUM;
    dst_mean[0] /= SRC_NUM;
    dst_mean[1] /= SRC_NUM;
    STUDY_DBG("%f %f %f %f \n", src_mean[0], src_mean[1], dst_mean[0], dst_mean[1]);

    double src_demean[SRC_NUM][2] = {0.0};
    double dst_demean[SRC_NUM][2] = {0.0};

    for(i=0; i<SRC_NUM; i++)
    {
        src_demean[i][0] = src[2*i] - src_mean[0];
        src_demean[i][1] = src[2*i+1] - src_mean[1];
        dst_demean[i][0] = dst[2*i] - dst_mean[0];
        dst_demean[i][1] = dst[2*i+1] - dst_mean[1];
        STUDY_DBG("%f %f %f %f\n", src_demean[i][0], src_demean[i][1], dst_demean[i][0], dst_demean[i][1]);
    }

    double A[SRC_DIM][SRC_DIM] = {0.0};
    for(i=0; i<SRC_DIM; i++)
    {
        for(k=0; k<SRC_DIM; k++)
        {
            for(j=0; j<SRC_NUM; j++)
            {
                A[i][k] += dst_demean[j][i]*src_demean[j][k];
            }
            A[i][k] /= SRC_NUM;
            STUDY_DBG("A[%d][%d] = %f \n", i, k, A[i][k]);
        }
    }

    double d[SRC_DIM] = {1, 1};
    double det_A = A[0][0]*A[1][1] - A[1][0]*A[1][0];
    STUDY_DBG("%f \n", det_A);
    if(det_A < 0)
        d[SRC_DIM-1] = -1;

    double *TT = (double *)malloc((SRC_DIM+1)*(SRC_DIM+1)*sizeof(double));
    double (*T)[SRC_DIM+1] = TT;
    T[0][0] = 1;
    T[0][1] = 0;
    T[0][2] = 0;
    T[1][0] = 0;
    T[1][1] = 1;
    T[1][2] = 0;
    T[2][0] = 0;
    T[2][1] = 0;
    T[2][2] = 1;

    double U[SRC_DIM][SRC_DIM] = {0};
    double S[SRC_DIM] = {0};
    double V[SRC_DIM][SRC_DIM] = {0};
    svd22(&A[0][0], &U[0][0], S, &V[0][0]);
    STUDY_DBG("S[0] = %f S[1] = %f\n", S[0], S[1]);
    STUDY_DBG("U[0][0] = %f U[0][1] = %f U[1][0] = %f U[1][1] = %f\n", U[0][0], U[0][1], U[1][0], U[1][1]);
    STUDY_DBG("V[0][0] = %f V[0][1] = %f V[1][0] = %f V[1][1] = %f\n", V[0][0], V[0][1], V[1][0], V[1][1]);

    double diag_d[SRC_DIM][SRC_DIM] = 
        {
            {1.0, 0.0},
            {0.0, 1.0}
        };
    T[0][0] = U[0][0]*V[0][0] + U[0][1]*V[1][0];
    T[0][1] = U[0][0]*V[0][1] + U[0][1]*V[1][1];
    T[1][0] = U[1][0]*V[0][0] + U[1][1]*V[1][0];
    T[1][1] = U[1][0]*V[0][1] + U[1][1]*V[1][1];
    STUDY_DBG("T[0][0] = %f T[0][1] = %f T[1][0] = %f T[1][1] = %f \n", T[0][0], T[0][1], T[1][0], T[1][1]);

    double scale = 1.0;
    double src_demean_mean[SRC_DIM] = {0.0};
    double src_demean_var[SRC_DIM] = {0.0};
    for(i=0; i<SRC_NUM; i++)
    {
        src_demean_mean[0] += src_demean[i][0];
        src_demean_mean[1] += src_demean[i][1];
    }
    src_demean_mean[0] /= SRC_NUM;
    src_demean_mean[1] /= SRC_NUM;
    
    for(i=0; i<SRC_NUM; i++)
    {
        src_demean_var[0] += (src_demean_mean[0] - src_demean[i][0])*(src_demean_mean[0] - src_demean[i][0]);
        src_demean_var[1] += (src_demean_mean[1] - src_demean[i][1])*(src_demean_mean[1] - src_demean[i][1]);
    }
    src_demean_var[0] /= (SRC_NUM);
    src_demean_var[1] /= (SRC_NUM);
    STUDY_DBG("%f %f\n", src_demean_var[0], src_demean_var[1]);
    scale = 1.0 / (src_demean_var[0] + src_demean_var[1]) *(S[0] + S[1]);
    STUDY_DBG("scale = %f\n", scale);
    T[0][2] = dst_mean[0] - scale*(T[0][0]*src_mean[0] + T[0][1]*src_mean[1]);
    T[1][2] = dst_mean[1] - scale*(T[1][0]*src_mean[0] + T[1][1]*src_mean[1]);
    T[0][0] *= scale;
    T[0][1] *= scale;
    T[1][0] *= scale;
    T[1][1] *= scale;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            STUDY_DBG("T[%d][%d] = %f ", i, j, T[i][j]);
        STUDY_DBG("\n");
    }
    return TT;
}

ZqImage *study_similarity(ZqImage* bmpImg, double *T)
{
    //相似变换
    ZqImage* bmpImgSim;
    int width = 0;
    int height = 0;
    int step = 0;
    int sim_step = 0;
    int channels = 1;
    int i, j, k;
    width = bmpImg->width;
    height = bmpImg->height;
    channels = bmpImg->channels;

    //初始化处理后图片的信息
    bmpImgSim = (ZqImage*)malloc(sizeof(ZqImage));
    bmpImgSim->channels = channels;
    bmpImgSim->width = 128;
    bmpImgSim->height = 128;

    step = channels * width;
    sim_step = bmpImgSim->channels * bmpImgSim->width;
    bmpImgSim->imageData =
        (unsigned char*)malloc(sizeof(unsigned char)*bmpImgSim->width*bmpImgSim->height*bmpImgSim->channels);

    //初始化图像
    for (i=0; i<bmpImgSim->height; i++)
    {
        for (j=0; j<bmpImgSim->width; j++)
        {
            for (k = 0; k < channels; k++)
            {
                bmpImgSim->imageData[(bmpImgSim->height-1-i)*sim_step + j*bmpImgSim->channels + k] = 0;
            }
        }
    }

    int pre_x, pre_y, after_x, after_y;//缩放前对应的像素点坐标
    int x, y;
    unsigned short color[2][2];
    double (*TT)[3] = T;
    for(i = 0;i < bmpImgSim->height;i++)
    {
        for(j = 0;j < bmpImgSim->width;j++)
        {
            pre_x = (int)(TT[0][0] * j + TT[0][1] * i + TT[0][2]);
            pre_y = (int)(TT[1][0] * j + TT[1][1] * i + TT[1][2]);

            pre_x <<= 8;
            pre_y <<= 8;
            y = pre_y & 0xFF;
            x = pre_x & 0xFF;
            pre_x >>= 8;
            pre_y >>= 8;
            if(pre_x<0 || pre_x > (width-1) || pre_y<0 || pre_y>(height-1))
				    continue;
            for(k=0; k<channels; k++)
            {
                //双线性内插
                color[0][0] = bmpImg->imageData[pre_y*step + pre_x * channels + k];
                color[1][0] = bmpImg->imageData[pre_y*step + (pre_x + 1) * channels + k];
                color[0][1] = bmpImg->imageData[(pre_y + 1)*step + pre_x * channels + k];
                color[1][1] = bmpImg->imageData[(pre_y + 1)*step + (pre_x + 1) * channels + k];
                int final = (0x100 - x)*(0x100 - y)*color[0][0] + x * (0x100 - y)*color[1][0] + (0x100 - x)*y*color[0][1] + x * y*color[1][1];
                final = final >> 16;
                bmpImgSim->imageData[i * sim_step + j*channels +k] = final;
            }
        }
    }
    return bmpImgSim;
}

ZqImage *study_imshear(ZqImage *img, int angle, char axis)
{
    //图片错切处理
    ZqImage *img_shear;
    double x_shear_angle;//要错切的弧度数
    double y_shear_angle;//要错切的弧度数
    int width = 0;
    int height = 0;
    int step = 0;
    int shear_step = 0;
    int channels = 1;
    int x, y;
    unsigned short color[2][2];
    unsigned char blue[2][2];
    unsigned char green[2][2];
    unsigned char red[2][2];
    unsigned short rgb;
    int i, j, k;
    width = img->width;
    height = img->height;
    channels = img->channels;
    int midx_pre, midy_pre, midx_aft, midy_aft;//错切前的中心点的坐标
    midx_pre = width / 2;
    midy_pre = height / 2;
    int pre_i, pre_j, after_i, after_j;//错切前后对应的像素点坐标
    x_shear_angle = 1.0 * angle * PI / 180;
    y_shear_angle = 1.0 * angle * PI / 180;
    double x_tan_calc = tan((double)x_shear_angle);
    double y_tan_calc = tan((double)y_shear_angle);
    printf("x_tan_calc = %f \n", x_tan_calc);
    //初始化错切后图片的信息
    img_shear = (ZqImage *)malloc(sizeof(ZqImage));
    img_shear->channels = channels;
    if(axis == 'x')
    {
        img_shear->width = width + abs(x_tan_calc * height);
        img_shear->height = height;
        if(img_shear->width % 4 != 0)
			img_shear->width = (img_shear->width / 4 + 1) * 4;
    }
	else
    {
        img_shear->width = width;
        img_shear->height = height + abs(y_tan_calc * width);
    }
    midx_aft = img_shear->width / 2;
    midy_aft = img_shear->height / 2;
    img_shear->imageData = (unsigned char*)malloc(sizeof(unsigned char)*img_shear->width*img_shear->height*channels);
	step = width*channels;
    shear_step = img_shear->width*channels;
	int color_step = width * height;
	int rot_color_step = img_shear->width * img_shear->height;

    //坐标变换
    for (i = 0; i < img_shear->height; i++)
    {
        for (j = 0; j < img_shear->width; j++)
        {
            if(axis == 'x')
            {
                pre_i = i - midy_aft + midy_pre;
                pre_j = (j ) - x_tan_calc*(i) - midx_aft + midy_aft*x_tan_calc + midx_pre;
            }
            else
            {
                pre_i = i - y_tan_calc*(j) - midy_aft + midx_aft*y_tan_calc + midy_pre;
                pre_j = j - midx_aft + midx_pre;
            }

            if (pre_i >= 0 && pre_i < height && pre_j >= 0 && pre_j < width)//在原图范围内
            {
                for (k = 0; k < channels; k++)
                {
                    img_shear->imageData[i*shear_step + j *channels + k] = img->imageData[pre_i*step + pre_j*channels + k];
                }

            }
        }
    }
    return img_shear;
}


#define N 8    //测试矩阵维数定义

//按第一行展开计算|A|
double getA(double arcs[N][N], int n)
{
    if (n == 1)
    {
        return arcs[0][0];
    }
    double ans = 0;
    double temp[N][N] = { 0.0 };
    int i, j, k;
    for (i = 0; i<n; i++)
    {
        for (j = 0; j<n - 1; j++)
        {
            for (k = 0; k<n - 1; k++)
            {
                temp[j][k] = arcs[j + 1][(k >= i) ? k + 1 : k];

            }
        }
        double t = getA(temp, n - 1);
        if (i % 2 == 0)
        {
            ans += arcs[0][i] * t;
        }
        else
        {
            ans -= arcs[0][i] * t;
        }
    }
    return ans;
}

//计算每一行每一列的每个元素所对应的余子式，组成A*
void  getAStart(double arcs[N][N], int n, double ans[N][N])
{
    if (n == 1)
    {
        ans[0][0] = 1;
        return;
    }
    int i, j, k, t;
    double temp[N][N];
    for (i = 0; i<n; i++)
    {
        for (j = 0; j<n; j++)
        {
            for (k = 0; k<n - 1; k++)
            {
                for (t = 0; t<n - 1; t++)
                {
                    temp[k][t] = arcs[k >= i ? k + 1 : k][t >= j ? t + 1 : t];
                }
            }


            ans[j][i] = getA(temp, n - 1);  //此处顺便进行了转置
            if ((i + j) % 2 == 1)
            {
                ans[j][i] = -ans[j][i];
            }
        }
    }
}

//得到给定矩阵src的逆矩阵保存到des中。
bool GetMatrixInverse(double src[N][N], int n, double des[N][N])
{
    double flag = getA(src, n);
    double t[N][N];
    if (0 == flag)
    {
        printf("原矩阵行列式为0，无法求逆。请重新运行\n");
        return false;//如果算出矩阵的行列式为0，则不往下进行
    }
    else
    {
        getAStart(src, n, t);
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                des[i][j] = t[i][j] / flag;
            }

        }
    }

    return true;
}

ZqImage *study_PerspectiveTransform_new(ZqImage* bmpImg)
{
    //投影变换
    ZqImage* bmpImgPer;
    int width = 0;
    int height = 0;
    int step = 0;
    int salt_step = 0;
    int channels = 1;
    int i, j, k;
    width = bmpImg->width;
    height = bmpImg->height;
    channels = bmpImg->channels;

    //初始化处理后图片的信息
    bmpImgPer = (ZqImage*)malloc(sizeof(ZqImage));
    bmpImgPer->channels = channels;
    bmpImgPer->width = width;
    bmpImgPer->height = height;

    step = channels * width;
    salt_step = bmpImgPer->channels * bmpImgPer->width;
    bmpImgPer->imageData =
        (unsigned char*)malloc(sizeof(unsigned char)*bmpImgPer->width*bmpImgPer->height*bmpImgPer->channels);

    //初始化图像
    for (i=0; i<bmpImgPer->height; i++)
    {
        for (j=0; j<bmpImgPer->width; j++)
        {
            bmpImgPer->imageData[(bmpImgPer->height-1-i)*salt_step+j] = 0;
        }
    }

    int P[8] = {
                    0, 0,
                    width-1, 0,
                    0, height-1,
                    width-1, height-1,
                };
    int uv[8] = {
                46, 83, // top left
                264, 0, // top right
                0, 350,// bottom left
                224, 350
            };
    double src[8][8] =
    {
        { P[0], P[1], 1, 0, 0, 0, -uv[0]*P[0], -uv[0]*P[1] },
        { 0, 0, 0, P[0], P[1], 1, -uv[1]*P[0], -uv[1]*P[1] },

        { P[2], P[3], 1, 0, 0, 0, -uv[2]*P[2], -uv[2]*P[3] },
        { 0, 0, 0, P[2], P[3], 1, -uv[3]*P[2], -uv[3]*P[3] },

        { P[4], P[5], 1, 0, 0, 0, -uv[4]*P[4], -uv[4]*P[5] },
        { 0, 0, 0, P[4], P[5], 1, -uv[5]*P[4], -uv[5]*P[5] },

        { P[6], P[7], 1, 0, 0, 0, -uv[6]*P[6], -uv[6]*P[7] },
        { 0, 0, 0, P[6], P[7], 1, -uv[7]*P[6], -uv[7]*P[7] }
    };
    double matrix_after[N][N]={0};
    bool flag = GetMatrixInverse(src, N, matrix_after);
    if (false == flag) {
        printf("求不出系数\n");
        return;
    }
    printf("逆矩阵：\n");

    for (int i = 0; i<8; i++)
    {
        for (int j = 0; j<8; j++)
        {
            printf("%f .", matrix_after[i][j]);
        }
        printf("\n");
    }

    double xs[8];
    for (int i = 0; i < 8; i++) {
        double sum = 0;
        for (int t = 0; t < 8; t++) {
            sum += matrix_after[i][t] * uv[t];
        }
        xs[i] = sum;
    }

    for(i = 0;i < bmpImgPer->height;i++)
    {
        for(j = 0;j < bmpImgPer->width;j++)
        {
            double px = xs[0] * j + xs[1] * i + xs[2];
            double py = xs[3] * j + xs[4] * i + xs[5];
            double p = xs[6] * j + xs[7] * i + 1;

            int x = px / p;
            int y = py / p;
            if(x<0 || x > (width-1) || y<0 || y>(height-1))
                continue;
            for(k=0; k<channels; k++)
            {
                bmpImgPer->imageData[i * salt_step + j*channels +k] = bmpImg->imageData[y * step + x*channels + k];
            }
        }
    }
    return bmpImgPer;
}

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

void times(PerspectiveTransform *p, PerspectiveTransform *other, PerspectiveTransform *ret_p)
{
    ret_p->a11 = p->a11 * other->a11 + p->a21 * other->a12 + p->a31 * other->a13;
    ret_p->a21 = p->a11 * other->a21 + p->a21 * other->a22 + p->a31 * other->a23;
    ret_p->a31 = p->a11 * other->a31 + p->a21 * other->a32 + p->a31* other->a33;
    ret_p->a12 = p->a12 * other->a11 + p->a22 * other->a12 + p->a32 * other->a13;
    ret_p->a22 = p->a12 * other->a21 + p->a22 * other->a22 + p->a32 * other->a23;
    ret_p->a32 = p->a12 * other->a31 + p->a22 * other->a32 + p->a32 * other->a33;
    ret_p->a13 = p->a13 * other->a11 + p->a23 * other->a12 + p->a33 * other->a13;
    ret_p->a23 = p->a13 * other->a21 + p->a23 * other->a22 + p->a33 * other->a23;
    ret_p->a33 = p->a13 * other->a31 + p->a23 * other->a32 + p->a33 * other->a33;
}

void quadrilateralToQuadrilateral(PerspectiveTransform *ret_p, float x0, float y0, float x1, float y1,float x2, float y2, float x3, float y3,
                                float x0p, float y0p, float x1p, float y1p, float x2p, float y2p, float x3p, float y3p)
{
    PerspectiveTransform q_to_s;
    PerspectiveTransform s_to_q;
    quadrilateralToSquare(&q_to_s, x0, y0, x1, y1, x2, y2, x3, y3);
    squareToQuadrilateral(&s_to_q, x0p, y0p, x1p, y1p, x2p, y2p, x3p, y3p);
    times(&s_to_q, &q_to_s, ret_p);
}

void quadrilateralToSquare(PerspectiveTransform *ret_p, float x0, float y0, float x1, float y1,
                            float x2, float y2, float x3, float y3) 
{
  // Here, the adjoint serves as the inverse:
  PerspectiveTransform p;
  squareToQuadrilateral(&p, x0, y0, x1, y1, x2, y2, x3, y3);
  buildAdjoint(&p, ret_p);
}

void squareToQuadrilateral(PerspectiveTransform *ret_p, float x0, float y0, float x1, float y1,
                            float x2, float y2, float x3, float y3)
{
      float dx3 = x0 - x1 + x2 - x3;
      float dy3 = y0 - y1 + y2 - y3;
      if (dx3 == 0.0f && dy3 == 0.0f) 
      {
        ret_p->a11 = x1 - x0;
        ret_p->a21 = x2 - x1;
        ret_p->a31 = x0;
        ret_p->a12 = y1 - y0;
        ret_p->a22 = y2 - y1;
        ret_p->a32 = y0;
        ret_p->a13 = 0.0f;
        ret_p->a23 = 0.0f;
        ret_p->a33 = 1.0f;
      } 
      else 
      {
        float dx1 = x1 - x2;
        float dx2 = x3 - x2;
        float dy1 = y1 - y2;
        float dy2 = y3 - y2;
        float denominator = dx1 * dy2 - dx2 * dy1;
        float a13 = (dx3 * dy2 - dx2 * dy3) / denominator;
        float a23 = (dx1 * dy3 - dx3 * dy1) / denominator;
        ret_p->a11 = x1 - x0 + a13 * x1;
        ret_p->a21 = x3 - x0 + a23 * x3;
        ret_p->a31 = x0;
        ret_p->a12 = y1 - y0 + a13 * y1;
        ret_p->a22 = y3 - y0 + a23 * y3;
        ret_p->a32 = y0;
        ret_p->a13 = a13;
        ret_p->a23 = a23;
        ret_p->a33 = 1.0f;
      }
}

void buildAdjoint(PerspectiveTransform *p, PerspectiveTransform *ret_p) 
{
    ret_p->a11 = p->a22 * p->a33 - p->a23 * p->a32;
    ret_p->a21 = p->a23 * p->a31 - p->a21 * p->a33;
    ret_p->a31 = p->a21 * p->a32 - p->a22 * p->a31;
    ret_p->a12 = p->a13 * p->a32 - p->a12 * p->a33;
    ret_p->a22 = p->a11 * p->a33 - p->a13 * p->a31;
    ret_p->a32 = p->a12 * p->a31 - p->a11 * p->a32;
    ret_p->a13 = p->a12 * p->a23 - p->a13 * p->a22;
    ret_p->a23 = p->a13 * p->a21 - p->a11 * p->a23;
    ret_p->a33 = p->a11 * p->a22 - p->a12 * p->a21;
}

void transformPoints(PerspectiveTransform *p, float *points, int len)
{
  int max = len;
  int i = 0;
  for (i = 0; i < max; i += 2) {
    float x = points[i];
    float y = points[i + 1];
    float denominator = p->a13 * x + p->a23 * y + p->a33;
    points[i] = (p->a11 * x + p->a21 * y + p->a31) / denominator;
    points[i + 1] = (p->a12 * x + p->a22 * y + p->a32) / denominator;
  }
}

ZqImage *study_PerspectiveTransform(ZqImage* bmpImg)
{
    //投影变换
    ZqImage* bmpImgPer;
    int width = 0;
    int height = 0;
    int step = 0;
    int salt_step = 0;
    int channels = 1;
    int i, j, k;
    width = bmpImg->width;
    height = bmpImg->height;
    channels = bmpImg->channels;

    //初始化处理后图片的信息
    bmpImgPer = (ZqImage*)malloc(sizeof(ZqImage));
    bmpImgPer->channels = channels;
    bmpImgPer->width = width;
    bmpImgPer->height = height;

    step = channels * width;
    salt_step = bmpImgPer->channels * bmpImgPer->width;
    bmpImgPer->imageData =
        (unsigned char*)malloc(sizeof(unsigned char)*bmpImgPer->width*bmpImgPer->height*bmpImgPer->channels);

    //初始化图像
    for (i=0; i<bmpImgPer->height; i++)
    {
        for (j=0; j<bmpImgPer->width; j++)
        {
            bmpImgPer->imageData[(bmpImgPer->height-1-i)*salt_step+j] = 0;
        }
    }

    PerspectiveTransform p;
    quadrilateralToQuadrilateral(&p,
                                0, 0,
                                width-1, 0,
                                0, height-1,
                                width-1, height-1,
                                46, 83, // top left
                                264, 0, // top right
                                0, 350,// bottom left
                                224, 350);

    float *ponits = (float *)malloc(sizeof(float)*height*width*2);
    k = 0;
    for(i=0; i<height; i++)
    {
		for(j=0; j<width; j++)
        {
            ponits[k++] = (float)j;
            ponits[k++] = (float)i;
		}
	}
    
    transformPoints(&p, ponits, height*width*2);
    
    for(i = 0;i < bmpImgPer->height;i++)
    {
        for(j = 0;j < bmpImgPer->width;j++)
        {
            
            int tmp = i*width + j;
            //printf("**%d %d\n", i, j);
            int x = ponits[tmp*2];
		    int y = ponits[tmp*2+1];
            if(x<0 || x > (width-1) || y<0 || y>(height-1))
				    continue;
            for(k=0; k<channels; k++)
            {
                bmpImgPer->imageData[i * salt_step + j*channels +k] = bmpImg->imageData[y * step + x*channels + k];
            }
        }
    }
    free(ponits);
    return bmpImgPer;
}

ZqImage *study_add_salt_pepper_noise(ZqImage* bmpImg)
{
    //生成椒盐噪声
    ZqImage* bmpImgSalt;
    int width = 0;
    int height = 0;
    int step = 0;
    int salt_step = 0;
    int channels = 1;
    int i, j, k;
    width = bmpImg->width;
    height = bmpImg->height;
    channels = bmpImg->channels;

    //初始化处理后图片的信息
    bmpImgSalt = (ZqImage*)malloc(sizeof(ZqImage));
    bmpImgSalt->channels = channels;
    bmpImgSalt->width = width;
    bmpImgSalt->height = height;

    step = channels * width;
    salt_step = bmpImgSalt->channels * bmpImgSalt->width;
    bmpImgSalt->imageData =
        (unsigned char*)malloc(sizeof(unsigned char)*bmpImgSalt->width*bmpImgSalt->height*bmpImgSalt->channels);

    //初始化图像
    for (i=0; i<bmpImgSalt->height; i++)
    {
        for (j=0; j<bmpImgSalt->width; j++)
        {
            bmpImgSalt->imageData[(bmpImgSalt->height-1-i)*salt_step+j] = 0;
        }
    }
    //滤波处理
    srand(time(NULL));
    int noise_p;
    for(i = 0;i < bmpImgSalt->height;i++)
    {
        for(j = 0;j < bmpImgSalt->width;j++)
        {
            for(k=0; k<channels; k++)
            {
                noise_p = rand() % 10;
                if (noise_p == 0)
                {
                    int temp = rand() % 2;
                    if (temp)
                        bmpImgSalt->imageData[i * salt_step + j*channels +k] = 0x00;
                    else
                        bmpImgSalt->imageData[i * salt_step + j*channels +k] = 0xff;
                }
                else
                    bmpImgSalt->imageData[i * salt_step + j*channels +k] = bmpImg->imageData[i * step + j*channels + k];
            }
        }
    }

    return bmpImgSalt;
}

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
    short color = 0;
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
            /* Arithmetic Mean Filter */
            int m = 0;
            for (m = 0; m < 9; m++)
                color += value[m];
            color /= 9;
            bmpImgFilter->imageData[i * filter_step + j*channels +k] = color;
            /* Contra-Harmonic Mean Filter */
            int Q = 2;
            double num = 0.0, den = 0.0;
            for (m = 0; m < 9; m++){
                num += pow(value[m], Q+1);
                den += pow(value[m], Q);
            }
            color = (short)(num / den);
            if (color < 0x00)
                bmpImgFilter->imageData[i * filter_step + j*channels +k] = 0x00;
            else if (color > 0xff)
                bmpImgFilter->imageData[i * filter_step + j*channels +k] = 0xff;
            else
                bmpImgFilter->imageData[i * filter_step + j*channels +k] = color;
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

ZqImage *study_3ch_to_2ch(ZqImage *img_3ch)
{
    //三通道图片转成供LCD显示的图片格式
    ZqImage *img_2ch;
    int width = 0;
    int height = 0;
    int channels = 1;
    int step_3ch = 0;
    int step_2ch = 0;
    int i, j;
    width = img_3ch->width;
    height = img_3ch->height;
    channels = img_3ch->channels;

    img_2ch = (ZqImage *)malloc(sizeof(ZqImage));
    img_2ch->channels = 2;
    img_2ch->width = width;
    img_2ch->height = height;
    step_3ch = channels * width;
    step_2ch = img_2ch->channels * img_2ch->width;
    img_2ch->imageData = (unsigned char*)malloc(sizeof(unsigned char)*img_2ch->width*img_2ch->height*img_2ch->channels);

    unsigned short blue;
    unsigned short green;
    unsigned short red;
    unsigned short rgb;

    //坐标变换
    for (j = 0; j < img_2ch->height; j++)
    {
        for (i = 0; i < img_2ch->width; i++)
        {
            blue = img_3ch->imageData[j * step_3ch + i * 3];
            green = img_3ch->imageData[j * step_3ch + i * 3 + 1];
            red = img_3ch->imageData[j * step_3ch + i * 3 + 2];
            rgb = (((red >> 3) & 0x1f) << 11) | (((green >> 2) & 0x3f) << 5) | (((blue >> 3) & 0x1f) << 0);

            img_2ch->imageData[j * step_2ch + i * 2] = (unsigned char)rgb & 0xff;
            img_2ch->imageData[j * step_2ch + i * 2 + 1] = (unsigned char)(rgb >> 8) & 0xff;
        }
    }
    return img_2ch;
}

ZqImage *study_2ch_to_3ch(ZqImage *img_2ch)
{
    //LCD处理的图片读出转成三通道bmp格式
    ZqImage *img_3ch;
    int width = 0;
    int height = 0;
    int channels = 1;
    int step_2ch = 0;
    int step_3ch = 0;
    int i, j;
    width = img_2ch->width;
    height = img_2ch->height;
    channels = img_2ch->channels;

    img_3ch = (ZqImage *)malloc(sizeof(ZqImage));
    img_3ch->channels = 3;
    img_3ch->width = width;
    img_3ch->height = height;
    step_2ch = channels * width;
    step_3ch = img_3ch->channels * img_3ch->width;
    img_3ch->imageData = (unsigned char*)malloc(sizeof(unsigned char)*img_3ch->width*img_3ch->height*img_3ch->channels);

    unsigned char blue;
    unsigned char green;
    unsigned char red;
    unsigned short rgb;

    //坐标变换
    for (j = 0; j < img_3ch->height; j++)
    {
        for (i = 0; i < img_3ch->width; i++)
        {
            rgb = img_2ch->imageData[j * step_2ch + i * 2] | (img_2ch->imageData[j * step_2ch + i * 2 + 1] << 8);
            
            blue = (rgb & 0x1f) << 3;
            green = ((rgb >> 5) & 0x3f) << 2;
            red = ((rgb >> 11) & 0x1f) << 3;

            img_3ch->imageData[j * step_3ch + i * 3] = blue;
            img_3ch->imageData[j * step_3ch + i * 3 + 1] = green;
            img_3ch->imageData[j * step_3ch + i * 3 + 2] = red;
        }
    }
    return img_3ch;
}

ZqImage *rgb_to_rrrgggbbb(ZqImage *bmpImg)
{
    /*
     * AI处理的像素在内存中是是这样的格式：rrr..ggg..bbb..
     * LCD的像素在内存中的格式是：rgbrgbrgbbrgb...
     */
    ZqImage *img_out;
    int width = 0;
    int height = 0;
    int channels = 1;
    int step = 0;
    int cov_step = 0;
    int i, j;
    width = bmpImg->width;
    height = bmpImg->height;
    channels = bmpImg->channels;

    img_out = (ZqImage *)malloc(sizeof(ZqImage));
    img_out->channels = 3;
    img_out->width = width;
    img_out->height = height;
    step = channels * width;
    cov_step = img_out->channels * img_out->width;
    img_out->imageData = (unsigned char*)malloc(sizeof(unsigned char)*img_out->width*img_out->height*img_out->channels);

    unsigned short blue;
    unsigned short green;
    unsigned short red;
    unsigned short rgb;
    int count = 0;

    for (j = 0; j < img_out->height; j++)
    {
        for (i = 0; i < img_out->width; i++)
        {
            blue = bmpImg->imageData[j * step + i * 3];
            img_out->imageData[count ++] = (unsigned char)blue & 0xff;
        }
    }
	for (j = 0; j < img_out->height; j++)
    {
        for (i = 0; i < img_out->width; i++)
        {
            green = bmpImg->imageData[j * step + i * 3 + 1];
            img_out->imageData[count ++] = (unsigned char)green & 0xff;
        }
    }
	for (j = 0; j < img_out->height; j++)
    {
        for (i = 0; i < img_out->width; i++)
        {
            red = bmpImg->imageData[j * step + i * 3 + 2];
            img_out->imageData[count ++] = (unsigned char)red & 0xff;
        }
    }
    return img_out;
}

ZqImage *rrrgggbbb_to_rgb(ZqImage *bmpImg)
{
    /*
     * AI处理的像素在内存中是是这样的格式：rrr..ggg..bbb..
     * LCD的像素在内存中的格式是：rgbrgbrgbbrgb...
     */
    ZqImage *img_out;
    int width = 0;
    int height = 0;
    int channels = 1;
    int step = 0;
    int cov_step = 0;
    int i, j;
    width = bmpImg->width;
    height = bmpImg->height;
    channels = bmpImg->channels;

    img_out = (ZqImage *)malloc(sizeof(ZqImage));
    img_out->channels = 3;
    img_out->width = width;
    img_out->height = height;
    step = channels * width;
    cov_step = img_out->channels * img_out->width;
    img_out->imageData = (unsigned char*)malloc(sizeof(unsigned char)*img_out->width*img_out->height*img_out->channels);

    unsigned short blue;
    unsigned short green;
    unsigned short red;
    unsigned short rgb;
    int count = 0;

    for (j = 0; j < img_out->height; j++)
    {
        for (i = 0; i < img_out->width; i++)
        {
            blue = bmpImg->imageData[count++];

            img_out->imageData[j * cov_step + i * 3 + 0] = (unsigned char)blue & 0xff;
        }
    }
	for (j = 0; j < img_out->height; j++)
    {
        for (i = 0; i < img_out->width; i++)
        {
            green = bmpImg->imageData[count++];

            img_out->imageData[j * cov_step + i * 3 + 1] = (unsigned char)green & 0xff;
        }
    }
	for (j = 0; j < img_out->height; j++)
    {
        for (i = 0; i < img_out->width; i++)
        {
            red = bmpImg->imageData[count++];

            img_out->imageData[j * cov_step + i * 3 + 2] = (unsigned char)red & 0xff;
        }
    }
    return img_out;
}


