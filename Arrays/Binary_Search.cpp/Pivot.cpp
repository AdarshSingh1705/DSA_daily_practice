<<<<<<< HEAD
#include<iostream>
using namespace std;

int getpivot(int arr[], int n){
    int start=0,end=n-1;

    while(start<end){
        int mid= start + (end-start)/2;
        if(arr[mid]>=arr[start]){
            start=mid+1;
        }
        else {
            end= mid;
        }
        
    return start;
    }

 }

int main() {
    int arr[]={5,6,7,8,9,10,1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]); 
    int ans=getpivot(arr,n);
    cout<<"pivot element is: "<< ans << endl;
     return 0;
=======
#include<iostream>
using namespace std;

int getpivot(int arr[], int n){
    int start=0,end=n-1;

    while(start<end){
        int mid= start + (end-start)/2;
        if(arr[mid]>=arr[start]){
            start=mid+1;
        }
        else {
            end= mid;
        }
        
    return start;
    }

 }

int main() {
    int arr[]={5,6,7,8,9,10,1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]); 
    int ans=getpivot(arr,n);
    cout<<"pivot element is: "<< ans << endl;
     return 0;
>>>>>>> 0aeb97f3a68c61b23cdc45085f5163f4cadaef77
}