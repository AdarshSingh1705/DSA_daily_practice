#include<iostream>
#include<algorithm>
using namespace std;

int first_occur(int arr[], int n, int key){
    int start =0, end = n-1;
    int mid = start +(end-start)/2;
    int result = -1;

    cout<< endl <<"First Occurence is at index: "<<endl;
    while(start <= end){
        if(key == arr[mid]){
            result = mid;
            end = mid-1;
        }
        else if(key > arr[mid]){
            start = mid +1;
        }
        else if(key < arr[mid]) {
         end = mid -1;
        }
          mid = start +(end-start)/2;
    }
   return result;
}

int last_occur(int arr[], int n, int key){
    int start =0, end = n-1;
    int mid = start +(end-start)/2;
    int  result = -1;
    cout <<"Last Occurence is at index: "<<endl;

    while(start<= end){
        if(key == arr[mid]){
           result = mid;
           start = mid+1;
        }
        else if(key > arr[mid]){
            start = mid +1;
        }
        else  if(key < arr[mid]) {
          end = mid -1;
        }
        mid = start +(end-start)/2;
    }
    return result;
}

int main(){
    int arr[] = {2,5,3,4,2,6,7,2,9,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 2;
    sort(arr, arr + n);
    cout<<"sorted array is: " ;
    for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
    }
    cout<< first_occur(arr, n, key) <<endl;
   cout<< last_occur(arr, n, key) << endl;

   return 0;
}
