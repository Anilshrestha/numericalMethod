#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
# define e 0.05
int j=1;

float fnvalue(int *fn, int size, float x)
{
    float value=0;
    int i;
    for (i =size; i>=0;i--)
    {
        value+=pow(x,i)*fn[i];
    }
    return value;
} 

int main(void)
{
    int size,i;
    float fx0,fx1,x2,Er,x0,x1;
    printf("\nEnter the max power: ");
    scanf("%d",&size);
    int fn[size];
    printf("\nEnter the co-efficients: ");
    for ( i = size; i>=0;i--)
        scanf("%d",&fn[i]);       
    printf("\n\nEnter your guess: ");
    scanf("%f%f",&x0,&x1);
    fx0 = fnvalue(fn,size,x0);
    while(1)
    {
            printf("Iteration %d\n",j++);
            printf("--------------------\n");
            fx1 = fnvalue(fn,size,x1);
            x2=x1-(fx1*(x1-x0))/(fx1-fx0);
            Er=(x2-x1)/x2;
            if(Er<0)
            {
                    Er*=-1;
            }
    
            {
                Er=Er;
                
            }
            printf("x0=%f\tx1=%f\tfx0=%f\tfx1=%f\tx2=%f",x0,x1,fx0,fx1,x2);       
            if(Er>e)
            {
                    x0=x1;
                    x1=x2;
                    fx0=fx1;       
            }
            else
            {
                printf("\n\nThe root is %f",x2);
                break;
            }
            printf("\n");
                 
    }
    getch();
    return 0;
}


