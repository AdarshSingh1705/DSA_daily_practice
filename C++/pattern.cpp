#include<iostream>
using namespace std;

int main(){
    int n;
    int i=1;
    cout<<"enter the number of rows"<< endl;
    cin>>n;
      
     while(i<=n){
        int j=1;
        char ch = 'A'+i-1;
        while(j<=n){
            cout<< ch <<" ";
                j=j+1;
        }
        i=i+1;
        cout<< endl;
     }
     return 0;
}