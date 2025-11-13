#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of row"<< endl;
    cin >>n;
    int i=1;
    char ch;
    char a;
    while(i<=n){
        int j=0;
      //='A'+i;
        while(j<i){
         ch='A'+i+j-1;
         //a=ch+1;
         cout<< ch <<" ";
         j=j+1;   
        }
        i=i+1;
        cout<<endl;
    }
    return 0;
}