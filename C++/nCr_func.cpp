#include<iostream>
using namespace std;

long long  factorial(int  n){
    
        long long  fact = 1;
        for(int i=1; i<=n; i++){
         
         fact*=i;
        }
        return fact;
}
 
long long  nCr(int  n, int r){

    if (r > n || n < 0 || r < 0) {
        return 0; // Return 0 for invalid cases
    }

    long long  num = factorial(n);
    long long  denom = factorial(r) * factorial(n-r);

    return num/denom;

 }

int main(){

      int n , r;
      cout<< "enter the value of n and r"<<endl;
      cin>> n;
      cin>> r;
      long long combination = nCr(n , r);
      cout<<"number of possible combination is:- "<< combination << endl;

    return 0;
 }
