#include<iostream>
using namespace std;

int main(){
     int a,b;

     cout<<"enter the base number "<<endl;
      cin>> a;
     cout<<"enter the power"<<endl;
     cin>> b;
      int c=1;
      for(int i=1; i<=b; i++){
        c*=a;
      }
      cout<<"Value of a to the power b is:- "<< c;

     return 0;
}