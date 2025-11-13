#include<stdio.h>
#include<conio.h>

int main(){
    int num, reverse=0, rem;
    printf("Enter the nnumber: ");
    scanf("%d",&num);

    while(num>0){
        rem=num%10;
        reverse= reverse*10+rem;
        num=num/10;
    }
    printf("Reverse number is: %d", reverse);

    return 0;
}