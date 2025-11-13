#include<iostream>
using namespace std;

int main(){
    int n;
    cout<< "enter the number"<<endl;
    cin>>n;
    int i=2;
    int a=0;
    int b=0;
    while(i<=(n/2)){
         if(n%i==0){
            a=a+1;
            //cout<<"entered number is not prime"<<endl;
         }
         else{
             b=b+1;
            // cout<< "entered no. is not prime";
         }
         i=i+1;

    }
    if(a>=1){
         cout<<"entered num is not prime"<<endl;
    }
    else{
        cout<< " entered no. is  prime";
    }

    return 0;
}