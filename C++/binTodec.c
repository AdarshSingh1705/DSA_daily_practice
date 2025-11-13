#include<stdio.h>
#include<math.h>

int main(){
    int num, bin,dec,i=1;
    printf("Enter the binary number:");
    scanf("%d",&num);
     while(num>0){
        bin=num%10;
        dec=dec+bin*(pow(2,i));
        i++;
     }
     printf("decimal value is %d", dec);
     return 0;
}