#include<iostream>
#include<math.h>

using namespace std;
 
  int main(){
     int n;
     cout <<"enter any number"<< endl;
     cin>>n;
       int i=0;
     int ans=0;
    int bit=0;
    while(n != 0){

      bit = n & 1;
     ans = ( bit * pow(10,i) ) + ans;
        n = n >> 1;
        i++ ;
    }

    cout<< ans;


 //return 0;
}
 