<<<<<<< HEAD
#include<iostream>
using namespace std;
 
 int BinarySearch(int arr[], int n, int key){
  int start = 0, end = n-1;
       int mid = start + (end - start )/2;
       
       while(start <= end){
             if(key == arr[mid]){
                return mid+1;
             }
             else if(key < arr[mid]){
                end = mid-1;
             }
             else if(key > arr[mid]){
                start = mid+1;
             }
             mid = start + (end - start )/2;
       }
       return -1;
}


int main(){
    int arr[] = {7,9,11,23,45,55,69};
    int keyIndex = BinarySearch(arr, 7, 11);
    cout<< " Index of the 11 is: "<< keyIndex << endl;

    return 0;
}

=======
#include<iostream>
using namespace std;
 
 int BinarySearch(int arr[], int n, int key){
  int start = 0, end = n-1;
       int mid = start + (end - start )/2;
       
       while(start <= end){
             if(key == arr[mid]){
                return mid+1;
             }
             else if(key < arr[mid]){
                end = mid-1;
             }
             else if(key > arr[mid]){
                start = mid+1;
             }
             mid = start + (end - start )/2;
       }
       return -1;
}


int main(){
    int arr[] = {7,9,11,23,45,55,69};
    int keyIndex = BinarySearch(arr, 7, 11);
    cout<< " Index of the 11 is: "<< keyIndex << endl;

    return 0;
}

>>>>>>> 0aeb97f3a68c61b23cdc45085f5163f4cadaef77
     