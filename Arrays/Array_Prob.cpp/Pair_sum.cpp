<<<<<<< HEAD
#include<iostream>
#include<algorithm>
using namespace std;

void PairSum(int arr[], int n){
    cout<<"Pair sum is : "<<endl;
    for(int i=0; i<6; i++){
        for(int j=i+1; j<6; j++){
            if(arr[i]+arr[j] == 8){
        
            cout<< arr[i]<<' '<<arr[j]<<endl; 
            }
        }
    }
}

int main(){
    int arr[]={2,6,9,4,3,7};
    int n=6;
    cout<<"target element is 8."<<endl;
    sort(arr, arr+n);
    PairSum(arr, 6);
    return 0;
=======
#include<iostream>
#include<algorithm>
using namespace std;

void PairSum(int arr[], int n){
    cout<<"Pair sum is : "<<endl;
    for(int i=0; i<6; i++){
        for(int j=i+1; j<6; j++){
            if(arr[i]+arr[j] == 8){
        
            cout<< arr[i]<<' '<<arr[j]<<endl; 
            }
        }
    }
}

int main(){
    int arr[]={2,6,9,4,3,7};
    int n=6;
    cout<<"target element is 8."<<endl;
    sort(arr, arr+n);
    PairSum(arr, 6);
    return 0;
>>>>>>> 0aeb97f3a68c61b23cdc45085f5163f4cadaef77
}