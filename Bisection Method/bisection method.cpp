// Finding root of equation 2x^2+2x-8=0 assuming e=0.05,xl=1 and xu=2.
#include<stdio.h>
#include<conio.h>
int a0,a1,a2,a3,i=1;

inline float bisectionFunction(float x)
{
       return(a3*x*x*x + a2*x*x + a1*x + a0);
       
}
int main(void)
{
    float xl,xu,xm,e,fxl,fxu,fxm;
    printf("Enter the value of cofficient a3,a2,a1,a0:\n");
    scanf("%d %d %d %d",&a3,&a2,&a1,&a0);
    printf("\nEnter the value of xl,xu and E:\n");
    scanf("%f%f%f",&xl,&xu,&e);
    fxl=bisectionFunction(xl);
    fxu=bisectionFunction(xu);    
    while(1)
    {
            
            printf("\nIteration %d\n",i++);
            printf("...............\n\n\n");    
            xm=(xu+xl)/2;
            if((xu-xl)/xu<e)
            {
                  printf("\nThe root is %f",xm);
                  break;
                  
            }
            else
            {          
                fxm=bisectionFunction(xm);
                if((fxl * fxm)<0)
                {
                        xu=xm;
                }
                if((fxm*fxu)<0)
                {
                      xl=xm;   
                }
                printf("fxm=%.4f",fxm);
                printf(" fxl=%.4f",fxl);
                printf(" xm=%.4f",xm);
                printf(" xu=%.4f",xu);
                printf(" xl=%.4f",xl);
                printf("\n");
            }
    }
    
    getch();
    return 0;   
}
