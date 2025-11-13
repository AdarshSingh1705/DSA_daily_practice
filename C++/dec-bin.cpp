#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter an decimal number" << endl;
     cin>>n;
       int rem =0;
       int bin=0;
     while(n!=0){
        rem=n%2;
        bin=bin*10+rem;
        n=n/2;
    
     }

cout<< "binary number is"<< bin <<endl;
    return 0;
}