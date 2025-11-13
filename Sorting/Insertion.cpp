#include<iostream>
using namespace std;

void insertionsort(int arr[], int n){

    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev=prev-1;
        }
        arr[prev+1]=curr;
    }
}

void print(int arr[], int n){
    cout << "After for sorting: " ;
    for(int i =0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[]={6,4,9,8,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    // for(int i=1; i<=n-1; i++){
    //     int key=arr[i];
    //     int j= i-1;
    //     while(j>=0 && arr[j]>key){
    //        arr[j+1]=arr[j];
    //        j=j-1;
    //     }  
    //     cout<<key<<' '<<endl;
    //     arr[j+1]=key;
    // } 
        for(int i=0; i<n; i++){
    cout<<arr[i]<<' ';
    }cout << endl;

    insertionsort(arr, n);
    print(arr, n);
    
    return 0;   
}

// Insertion sort is stable
// Best case: O(n) when the array is already sorted
// Average case: O(n^2) when the array is randomly ordered
// Worst case: O(n^2) when the array is reverse sorted
// Space complexity: O(1) because it only uses a constant amount of space 