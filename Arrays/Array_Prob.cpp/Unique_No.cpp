<<<<<<< HEAD
#include<iostream>
using namespace std;

int unique(int arr[], int n){
       int ans=0;
       for(int i=0; i<n; i++){
        ans^=arr[i];
       }   
        return ans;
}

int main(){
    
    int arr[7]={2,3,5,2,6,3,6};
    cout<<"All element of Array"<<endl;
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"unique no. is "<<endl;
   int ans= unique(arr, 7); 
    cout<<ans;
    return 0;
=======
#include<iostream>
using namespace std;

int unique(int arr[], int n){
       int ans=0;
       for(int i=0; i<n; i++){
        ans^=arr[i];
       }   
        return ans;
}

int main(){
    
    int arr[7]={2,3,5,2,6,3,6};
    cout<<"All element of Array"<<endl;
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"unique no. is "<<endl;
   int ans= unique(arr, 7); 
    cout<<ans;
    return 0;
>>>>>>> 0aeb97f3a68c61b23cdc45085f5163f4cadaef77
}