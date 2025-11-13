#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of row"<< endl;
    cin >>n;
    int i=1;
   char ch;
      
    while(i<=n){
        int j=0;
        //ch='A'+n;
      //='A'+i;
        while(j<i){
         ch= 'A'+n-i+j;
         cout<< ch <<" ";
         j=j+1;
            
        }
        i=i+1;
        cout<<endl;
    }
    return 0;
}