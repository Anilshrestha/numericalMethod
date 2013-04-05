#include<stdio.h>
#include<conio.h>
int x[5] = {1,2,3,4,5};
float fx[5] = {0,7,26,63,124};
float pointx = 1.5;

int n = 4;
float nwfunction(int k , int i) {
      double ret = 0;
      if(k==i) {
               ret = fx[k];         
      }
      
      else if(k == i-1) {
           ret = (fx[i] - fx[k])/ (x[i] - x[k]);      
      }  
      
      else {
           ret = (  nwfunction(k+1,i) - nwfunction(k,i-1)  ) / (x[i] - x[k]);    
      } 
      return ret;   
}

int main(void) {
    float estimate = 0;
    int k = 0;
        for(int i=1; i<=n; i++) {
                float fxoi = nwfunction(k,i);
                printf("\na%d= %f\n",i,fxoi);
                
                float nwproduct = 1.0;
                
                for(int j=0; j<=i-1; j++) {
                         nwproduct *= (pointx - x[j]);         
                }        
                
                estimate += fxoi * nwproduct;
        }
        
        printf(" \nThe estimate of 2.5 is %f", estimate);
        getch();
        return 0;
}
