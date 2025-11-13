#include<iostream>
using namespace std;

void tripletSum(int arr[], int n){
       cout<<"Triplet Sum: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k]==12){
                    cout<<arr[i] <<" "<<arr[j] <<" "<<arr[k]<<endl;
                }
            }
        }
    } 
}

int main(){
    int arr[]={2,4,6,1,8,7,3,9};
      cout<<"target number is 12: "<<endl;
    tripletSum(arr,  8);
    return 0;
}