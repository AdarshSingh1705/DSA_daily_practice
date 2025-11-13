#include<stdio.h>
#include<conio.h>

int fabonacci(int num){
    int a=0,  b=1, c;
    if(num>=1){
        printf("%d ",a);
             
    }
    if(num>=2){
        printf("%d ",b);
        
    }
    while(num>2){
        c=a+b;
        a=b;
        b=c;
        printf("%d ",c);
        num--;
    }
}
int main(){
    int num, fab;
    printf("Enter the number: ");
    scanf("%d",&num);

    fab= fabonacci(num);
     return 0;
}