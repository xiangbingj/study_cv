#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Power(a, b) pow((a), (b))
#define Sqrt(a) sqrt((a))
#define Abs(a) fabs((a))
int main()
{
    double a1 = 267.22534;
    double a2 = -48.82566;
    double a3 = -184.26672;
    double a4 = 289.1574;
    
    double U[2][2] = {0.0};
    double S[2] = {0.0};
    double V[2][2] = {0.0};

    U[0][0] = (Power(a1,3) + a1*Power(a2,2) + a1*Power(a3,2) + 2*a2*a3*a4 - a1*Power(a4,2) - a1*Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/
         ((a1*a2 + a3*a4)*Sqrt(Power(Abs((Power(a1,3) + a1*Power(a2,2) + a1*Power(a3,2) + 2*a2*a3*a4 - a1*Power(a4,2) - a1*Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/(a1*a2 + a3*a4)),2) + 
             Power(Abs((Power(a1,2)*a3 - Power(a2,2)*a3 + Power(a3,3) + 2*a1*a2*a4 + a3*Power(a4,2) - a3*Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/(a1*a2 + a3*a4)),2)));
    U[0][1] = (Power(a1,3) + a1*Power(a2,2) + a1*Power(a3,2) + 2*a2*a3*a4 - a1*Power(a4,2) + a1*Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/
        ((a1*a2 + a3*a4)*Sqrt(Power(Abs((Power(a1,3) + a1*Power(a2,2) + a1*Power(a3,2) + 2*a2*a3*a4 - a1*Power(a4,2) + a1*Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/(a1*a2 + a3*a4)),2) + 
            Power(Abs((Power(a1,2)*a3 - Power(a2,2)*a3 + Power(a3,3) + 2*a1*a2*a4 + a3*Power(a4,2) + a3*Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/(a1*a2 + a3*a4)),2)));
    U[1][0] = Power(a1,2)*a3 - Power(a2,2)*a3 + Power(a3,3) + 2*a1*a2*a4 + a3*Power(a4,2) - a3*Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/
            ((a1*a2 + a3*a4)*Sqrt(Power(Abs((Power(a1,3) + a1*Power(a2,2) + a1*Power(a3,2) + 2*a2*a3*a4 - a1*Power(a4,2) - a1*Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/(a1*a2 + a3*a4)),2) + 
             Power(Abs((Power(a1,2)*a3 - Power(a2,2)*a3 + Power(a3,3) + 2*a1*a2*a4 + a3*Power(a4,2) - a3*Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/(a1*a2 + a3*a4)),2)));
    U[1][1] = (Power(a1,2)*a3 - Power(a2,2)*a3 + Power(a3,3) + 2*a1*a2*a4 + a3*Power(a4,2) + a3*Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/
         ((a1*a2 + a3*a4)*Sqrt(Power(Abs((Power(a1,3) + a1*Power(a2,2) + a1*Power(a3,2) + 2*a2*a3*a4 - a1*Power(a4,2) + a1*Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/(a1*a2 + a3*a4)),2) + 
             Power(Abs((Power(a1,2)*a3 - Power(a2,2)*a3 + Power(a3,3) + 2*a1*a2*a4 + a3*Power(a4,2) + a3*Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/(a1*a2 + a3*a4)),2)));
             
    S[0] = (Sqrt(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2) - Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/Sqrt(2),0);
    S[1] = (0,Sqrt(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2) + Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/Sqrt(2));

    V[0][0] = (Power(a1,2) - Power(a2,2) + Power(a3,2) - Power(a4,2) - Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/
         ((a1*a2 + a3*a4)*Sqrt(4 + Power(Abs((-Power(a1,2) + Power(a2,2) - Power(a3,2) + Power(a4,2) + Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/(a1*a2 + a3*a4)),2)));
    V[0][1] = (Power(a1,2) - Power(a2,2) + Power(a3,2) - Power(a4,2) + Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/
         ((a1*a2 + a3*a4)*Sqrt(4 + Power(Abs((Power(a1,2) - Power(a2,2) + Power(a3,2) - Power(a4,2) + Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/(a1*a2 + a3*a4)),2)));
    V[1][0] = 2/Sqrt(4 + Power(Abs((-Power(a1,2) + Power(a2,2) - Power(a3,2) + Power(a4,2) + Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/(a1*a2 + a3*a4)),2));
    V[1][1] = 2/Sqrt(4 + Power(Abs((Power(a1,2) - Power(a2,2) + Power(a3,2) - Power(a4,2) + Sqrt(-4*Power(a2*a3 - a1*a4,2) + Power(Power(a1,2) + Power(a2,2) + Power(a3,2) + Power(a4,2),2)))/(a1*a2 + a3*a4)),2));
    printf("%f \n", S[0]);
    return 0;
}