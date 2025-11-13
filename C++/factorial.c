#include<stdio.h>
#include<conio.h>

int factorial(int num){
    if(num==0 || num==1){
        return 1;
    }
    else{
        return num*factorial(num-1);
    }
}
int main(){
    int num, fact;

    printf("Enter the number: ");
    scanf("%d", &num);
    fact=factorial(num);
    printf("/factorial of the given number is: %d",fact);
    
    return 0;

}
