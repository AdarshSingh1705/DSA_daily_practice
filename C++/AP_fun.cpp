#include<iostream>
using namespace std;

int ap( int n){
        int Ap=0;
        int a1, d;
        cout<<"enter the first number and last number"<<endl;

     cin>> a1;
     cin>> d;
     Ap = a1 + (n-1)*d;

    return Ap;

}

int main(){
      int n;
      cout<< "enter the term"<<endl;
      cin>> n; 

      int nth = ap(n);
      cout<<"n'th term is:- "<< nth<<endl;
        
    return 0;
}