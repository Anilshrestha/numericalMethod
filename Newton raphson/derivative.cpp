#include<stdio.h>
#include<conio.h>
#include<math.h>
int* derivative(int *arr, int n)
{
     int i;
     for(i=1;i<=n;i++)
     {
            arr[i]=i*arr[i];
     }
     for(i=0;i<=n-1;i++)
     {
            arr[i]=arr[i+1];
     }
     
     return &(arr[0]);
}
int main(void)
{
    int n,i;
    int *gx;
    printf("Enter the highest degree of the equation:\n");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter the coefficient:\n");
    for(i=n;i>=0;i--)
    {
           scanf("%d",&arr[i]);
    }
    printf("\nThe derivative of the given equation is:\n");
    gx=derivative(arr,n);
    for(i=n-1;i>=0;i--)
    {
            if(gx[i]>0)
            {
                 printf("+ ");
            }
            else
                printf(" ");
            printf("%dx^%d",gx[i],i);        
    }
    getch();
    
    
    
}
