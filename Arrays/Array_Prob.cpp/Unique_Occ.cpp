#include<iostream>
#include<algorithm>
using namespace std;

int unique(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]==arr[i]){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int arr[]={2,4,3,5,6,7,8,9};
    int n=8;
    sort(arr, arr+n);
    int uni = unique(arr,8);
    if(uni==1){
        cout<<"Flase"<<endl;
    }
    else{
        cout<< "True"<<endl;
    }
    
    return 0;
}