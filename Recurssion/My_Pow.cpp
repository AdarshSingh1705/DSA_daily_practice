#include<iostream>
#include<math.h>
using namespace std;

double mypow(double x, int n){

    // This is naive method also not aplicable for all the test cases;
    
    // if(n==0){
    //     return 1;
    // }
    // if(n<0){
    //     x = 1/x;
    //     n = -n;
    // }
    // return x*mypow(x,n-1);

    //Applicable for all the test cases

    if(n==0){
        return 1;
    }
    long long absN = static_cast<long long>(n);
    if(n<0){
        x = 1/x;
        absN = -absN;
    }

    double half = mypow(x, absN/2);
    return (absN % 2 == 0)? half*half: half*half*x;
}

int main(){
    double x = 2.00000;
    double n = 8;
    cout <<  endl;
    cout <<  mypow(x,n) << endl;
    
    return 0;
}