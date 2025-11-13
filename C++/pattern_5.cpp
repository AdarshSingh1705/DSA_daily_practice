#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of row"<< endl;
    cin >>n;
    int i=0;
    char ch;
    while(i<n){
        int j=0;
      //='A'+i;
        while(j<3){
         ch='A'+i+j;
         cout<< ch <<" ";
         j=j+1;   
        }
        i=i+1;
        cout<<endl;
    }
    return 0;
}