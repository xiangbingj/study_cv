#ifndef ZQ_CV_H  
#define ZQ_CV_H
#include <stdbool.h> 

#define PI 3.1415926  
/*按字节对齐Start
  如果不按字节对齐，
  第一个struct定义为16bit，
  而BMP文件中实际为14bit，
  故读取会错位。
  --zhangquan
*/
//位图文件头bf
#pragma pack (push ,1)
typedef struct  
{  
    unsigned short bfType;  //文件标识符BM，0x424D 2bit
    unsigned int    bfSize;//文件的大小 4bit
    unsigned short    bfReserved1; //保留值,必须设置为0 2bit
    unsigned short    bfReserved2; //保留值,必须设置为0 2bit
    unsigned int    bfOffBits;//文件头的最后到图像数据位开始的偏移量 4bit
} BMPFileHeader;

//位图信息头bi  
typedef struct  
{  
    unsigned int  biSize;//信息头的大小
    int   biWidth;   //图像宽度
    int   biHeight;   //图像高度
    unsigned short   biPlanes; //图像的位面数
    unsigned short   biBitCount;//每个像素的位数
    unsigned int  biCompression;//压缩类型
    unsigned int  biSizeImage;//图像大小，字节
    int   biXPelsPerMeter; //水平分辨率
    int   biYPelsPerMeter; //垂直分辨率
    unsigned int   biClrUsed; //使用的色彩数
    unsigned int   biClrImportant;//重要的颜色数
} BMPInfoHeader;
//颜色表
typedef struct
{  
    unsigned char rgbBlue; //蓝色分量
    unsigned char rgbGreen; //绿色分量
    unsigned char rgbRed; //红色分量
    unsigned char rgbReserved; //保留值
} RgbQuad;

typedef struct
{
    int width;
    int height;
    int channels;
    unsigned char* imageData;
}ZqImage;
#pragma pack (pop)
/*按字节对齐End*/
ZqImage* imread(char* path);
bool imwrite(char* path, ZqImage* bmpImg);
ZqImage* imrotate(ZqImage* bmpImg,int Angle);
ZqImage* imscale(ZqImage* bmpImg,double dy,double dx);

#endif
