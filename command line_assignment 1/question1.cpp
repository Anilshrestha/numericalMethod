#include<stdio.h>
#include<conio.h>
int main( int argc, char *argv[] )
{
 int ctr,flag=0;
 for( ctr=1; ctr < argc; ctr++ )
 {
       flag++;
 }
 printf("The total number of argument passed is %d",flag);
 getch();
 return 0;
}
