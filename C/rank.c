#include<stdio.h>

#define MAX 10  //最大行(列)数
typedef struct
{ int m,n;
  double a[MAX][MAX];
} matrix;

void input_matrix(matrix *dat);
void output_matrix(matrix dat);
void exchang_row(double *a,double *b,int n);  //交换两行
void mul_row(double *a,double k,int n);  //将某一行乘以k
void add_row(double *a1,double *a2,double k,int n); //将a2行的k倍加到a1行上
int rank_matrix(matrix dat,matrix *res);

double A[4][5] =
{
    {1, 1, -2, 3, 0},
    {2, 1, -6, 4, -1},
    {3, 2, -6, 7, -1},
    {1, -1, -6, -1, 2}
};

int B[4][3] =
{
    {4, -2},
    {1, 2},

};
void main()
{
    matrix a,b;
    int r;
    input_matrix(&a);
    r=rank_matrix(a,&b);

    printf("The original matrix:\n");
    output_matrix(a);
    printf("After transforming:\n");
    output_matrix(b);
    printf("\nr(A)=%d\n",r);
}

void input_matrix(matrix *dat)   //输入矩阵
{
    int i, j;
    dat->m = 2;
    dat->n = 2;
    for(i=0; i<(dat->m); i++)
        for(j=0; j<(dat->n); j++)
        {
            dat->a[i][j] = B[i][j];
        }
}

void output_matrix(matrix dat)  //显示矩阵
{
    int m,n,i,j;
    m=dat.m;n=dat.n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%f ",dat.a[i][j]);
        printf("\n"); 
    } 
}

void exchang_row(double *a,double *b,int n)
{
    int i;
    double t;
    for(i=0;i<n;i++)
    {
        t=a[i];
        a[i]=b[i];
        b[i]=t;
    }
}

void mul_row(double *a,double k,int n)
{
    int i;
    for(i=0;i<n;i++)
        a[i] *= k;
}
void add_row(double *a1,double *a2,double k,int n)
{
    int i;
    for(i=0; i<n; i++)
        a1[i] += a2[i]*k;
}

int rank_matrix(matrix dat,matrix *res) //求秩(返回值为秩，第2个参数为变换得到的阶梯阵)
{
    int m,n,i;
    double t;
    int ri,ci;  //行标记与列标记
    int f_z;    //某列是否全为0的标志，为1表示全为0
    m=dat.m;
    n=dat.n;
    ri = 0;
    for(ci=0; ci<n; ci++)
    {
        f_z=1;
        for(i=ri; i<m; i++)
        {
            if(dat.a[i][ci] != 0)
            {
                if(i != ri)
                {
                    if(f_z)
                    {
                        exchang_row(&(dat.a[ri][ci]),&(dat.a[i][ci]),n-ci);
                    }
                    else
                    {
                        t=dat.a[i][ci];
                        mul_row(&(dat.a[i][ci]),dat.a[ri][ci],n-ci);
                        add_row(&(dat.a[i][ci]), &(dat.a[ri][ci]), -t, n-ci);
                    }
                }
                f_z=0;
            }
        }
        if(!f_z)
            ri++; 
    }
    *res=dat;
    return ri; 
}