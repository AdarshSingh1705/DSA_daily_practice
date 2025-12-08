#include <iostream>
using namespace std;


void printArray(int arr[], int n){
    cout<<"sorted array is: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl;
}

void sorting(int arr[], int n){
      int low=0, high = n-1;
    while(low < high){
        if(arr[low]==0){
            low++;
        }
        else if(arr[high]==1){
            high--;
        }
        else if(arr[low]==1 && arr[high]==0){
            swap(arr[low], arr[high]);
            low++; 
            high--;
        }   
    }
}

int main(){
    int arr[]={0,0,1,0,1,0,1,0,1,1,1,0,0,0};
    int n=14;
    cout<<"Array before sorting is: " <<endl;
    for (int i=0; i<14; i++){
        cout << arr[i]<<" ";
    }
    cout<<endl;
    
    sorting(arr, n);
    printArray(arr, n);
    return 0;
}