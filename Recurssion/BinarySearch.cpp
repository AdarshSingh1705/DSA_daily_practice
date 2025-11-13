#include<iostream>
using namespace std;
//  T C : log(n).

void print(int  arr[], int s, int e){

    for(int i = s; i <=e; i++){
        cout  << arr[i] << " ";
    } cout  << endl;
}

bool  binarySearch(int *arr, int s, int e, int k){
    cout << endl;
    print(arr, s, e);   

    if(s > e){
        return false;

        int mid = s + (e-s)/2;
        cout << "Value of the arr mid is  " << arr[mid]  << endl;

        if(arr[mid] == k){
            return true;
        }
        if(arr[mid] < k){
            return binarySearch(arr, mid+1, e, k);
        }
        else{
            return binarySearch(arr, s, mid-1, k);
        }
    }
}

int main(){
        int target;
        int size;
        int *arr = new int;
        cout<< "Enter the size of the array:  " ;
        cin >> size ;
        cout  << endl;
        cout << "Enter the array's elements: " ;
        for (int i = 0; i < size; i++){
            cin >> arr[i];
        } cout << endl;

        cout << "Enter the target element: ";
        cin >> target;
        cout << endl;

        int t = binarySearch(arr, 0, size-1, target);
        cout << t ;
        delete[]arr;
}