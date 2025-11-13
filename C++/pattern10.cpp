#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of row"<< endl;
    cin >>n;
    int i=1;
   //char ch;
      
    while(i<=n){
        int j=1;
       
        while(j<=n){
         if(j<=n-i){
            cout<<" ";
         }
         else{
            cout<<"@"<< " ";
         }
         j=j+1;
            
        }
        i=i+1;
        cout<<endl;
    }
    return 0;
}