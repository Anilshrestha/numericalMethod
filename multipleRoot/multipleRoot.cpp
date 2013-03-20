#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
# define e 0.000001

int * derivative ( int * fn, int size)
{
    int i;
    int * deriv = (int*)malloc(size-1);

    for ( i = size; i>0; i--)
    {
        deriv[i-1] = i * fn[i];
    }
    return deriv;
}

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

float newtraph( int size, int *fn, float x ) {
      float fx_value,fx1_value,x3;
      int *newDerivative = derivative ( fn, size);
      
      
      while(1)
    {
            
            
            fx_value = fnvalue(fn,size,x);
            
            fx1_value = fnvalue(newDerivative,size-1,x);
            
            x3=x-(fx_value/fx1_value);
            
            if((fabs((x3-x)/x3))<e)
            {
                    break;       
            }
            else
            {
                x=x3;
            } 
            return x3; 
            
    }      
}
void syndivision(float x,int n,int *arr)
{
     int i,j;
     int b[10];
     
     b[n] = arr[n];
     
     
     for (i=n-1; i>=0; i--) {
         b[i] = x * b[i+1] + arr[i];}
         
     
     for (i=0;i<n;i++){
         arr[i] = b[i+1];
         
         }

}

int main(void)
{
    int size,i;
    float value_newt , x;
    printf("\nEnter the max power: ");
    scanf("%d",&size);
    int root[size];
    int fn[size];
    printf("\nEnter the co-efficients: ");
    for ( i = size; i>=0;i--){
        scanf("%d",&fn[i]);}
    printf("\n\nEnter your guess: ");
    scanf("%f",&x);
    
    for (i=size;i>1;i--)
    {
        value_newt = newtraph(i, fn, x);
         x = ceil(value_newt);
        syndivision(x,size,fn);
        root[i-1] = x; 
        
    }
    root[0] = -(fn[0]/fn[1]);
    printf("\nThe root are : ");
    for (i =0; i<size;i++) {
       printf("\nRoot[%d] = %d\n ", i+1, root[i]);
    }
       
    getch();
    return 0;
}

