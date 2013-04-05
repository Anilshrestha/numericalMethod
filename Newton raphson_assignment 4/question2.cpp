#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
# define e 0.05
int count =0,j=1;
int * derivative ( int * fn, int size) {
    
    int i;
    int * deriv = (int*)malloc(size);

    for ( i = size; i>0; i--) {

        deriv[i-1] = i * fn[i];
        
    }
    count++;
    
    return deriv;
}

double fnvalue(int *fn, int size, float x) {
      
    float value=0;
    int i;
    for (i =size; i>=0;i--) {
        
        value+=pow(x,i)*fn[i];
        
    }
    return value;
} 

int main(void) {
    
    int size,i;
    float x;
    double fx_value,fx1_value,x3;
    printf("\nEnter the max power: ");
    scanf("%d",&size);
    int fn[4]={10,-9,3,4};
    int *newDerivative = derivative ( fn, size);
    printf("The derivative equation is:\n");
    for ( i = size-count; i>=0; i--)
       printf("%dx^%d ",newDerivative[i],i);
       
    printf("\n\nEnter your guess: ");
    scanf("%d",&x);

    while(1) {
             
            printf("Iteration %d\n",j++);
            printf("--------------------\n");
            
            fx_value = fnvalue(fn,size,x);
            
            fx1_value = fnvalue(newDerivative,size-count,x);
            
            x3=x-(fx_value/fx1_value);
            
            if((x3-x)/x3<e) {
                            
                    printf("The root is %f",x3);
                    break; 
                          
            }
            else {
                 
                printf("\nx=%f",x);
                x=x3;
                
            }
            
            printf("\tfx_val=%f\tfx1_val=%f\tx3=%f",fx_value,fx1_value,x3);
            printf("\n\n");     
    }
    getch();
    return 0;
}
