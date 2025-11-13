#include<iostream>
using namespace std;

void bubblesort(int arr[], int n){

    for (int i=0; i<n-1; i++){
    
        bool swapped = false;
        for(int j =0; j < n-i-1; j++){
      
           if(arr[j] > arr[j+1]){

            swap(arr[j], arr[j+1]);
            swapped = true;
        }
        if(swapped ==false){
            break;
        }
    }
}
}

void printarray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[]={8,2,4,1,5,9,7,3,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    bubblesort(arr, n);
    printarray(arr, n);
    //  bool swapped = false;

    // for(int i=0; i< n-1; i++){

    //     for(int j=0; j< n-i-1; j++){
    //         if(arr[j]>arr[j+1]){
    //             swap(arr[j],arr[j+1]);
    //             swapped = true;
    //         }
    //     } 
    //     if(swapped == false){
    //         break;
    //     }
    // }
 return 0;
}
 // time complexity is O(n^2) and space complexity is O(1).
 // this is the most inefficient sorting algorithm. it is used for small arrays. it is not used
 // in real time applications. it is used for educational purposes. it is used to understand
 // how sorting algorithms work. it is used to understand how to implement sorting algorithms.

// 1. Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements.
// 2. If they are in the correct order, it leaves them be. Otherwise, it
// 3. swaps the elements.
// 4. The pass through the list is repeated until the list is sorted.
// 5. The algorithm, which is a comparison sort, is named for the way smaller elements
// 6. "bubble" to the top of the list.
// 7. It is one of the simplest sorting algorithms to implement and is often used as a
// 8. teaching tool to introduce the general idea of sorting.
// 9. However, it is not efficient on large lists, and many more efficient algorithms such
// 10. as quicksort, mergesort, and heapsort are used in practice

