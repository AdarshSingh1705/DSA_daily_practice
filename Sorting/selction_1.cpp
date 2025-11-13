#include<iostream>
#include<stdlib.h>
using namespace std;

int selectionSort(int arr[], int n){

    for(int i =0; i < n-1; i++){
        int midIndex = i;

        for(int j = i+1; j < n; j++){

            if(arr[j] < arr[midIndex]){
                midIndex = j;
            }
        }
        while(midIndex != i){
            int temp = arr[midIndex];
            arr[midIndex] = arr[i];
            arr[i] = temp;
        }

    }
}

void print(int arr[], int n){
    for(int i =0; i < n; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[]={7,4,5,6,3,8,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
  
  for(int i=0; i < n-1; i++){
     int min_index = i;

    for(int j=i+1; j < n; j++){
        if(arr[min_index]>arr[j]){
            min_index=j;
        }    
    }
   swap(arr[i], arr[min_index ]);
}

cout<<"sorted array using selection sort is: ";
for(int i=0; i<=n-1; i++){
    cout<<arr[i]<<" ";
}

selectionSort(arr, n);
print(arr, n);

return 0;
}

// Time complexity: O(n^2)
// Space complexity: O(1)

//This code implements the selection sort algorithm, which sorts an array of integers in ascending order. The algorithm
