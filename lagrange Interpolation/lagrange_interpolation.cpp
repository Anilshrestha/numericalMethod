#include<stdio.h>
#include<conio.h>
double x[5]={1,2,3,4,5};
double fx[5]={1,1.4142,1.7321,2,2.2361};
int n=5;
double point=2.5;

double lagrange(int i)
{
       double value=1;
       for(int j=0;j<5;j++)
       {
            if(i!=j)
            {
                    value *=((point-x[j])/(x[i]-x[j]));
            }
       }
       return value;                           
}
int main()
{
    double estimate=0.0;
    for(int i=0;i<n;i++)
    {
            estimate += fx[i] * lagrange(i);
    }
    printf("\nThe required value of %lf  is %lf",point,estimate);            
    getch();
    return 0;
}
