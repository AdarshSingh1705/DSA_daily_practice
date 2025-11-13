#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of row"<< endl;
    cin >>n;
    int i=1;
   char ch='A';
      
    while(i<=n){
        int j=1;
         //char ch;
      //='A'+i;
        while(j<=i){
         
         cout<< ch <<" ";
         j=j+1;
         ch=ch+1;   
        }
        i=i+1;
        cout<<endl;
    }
    return 0;
}