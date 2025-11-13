#include <iostream>
#include<vector>
using namespace std;

bool isSorted(int *arr, int n){
    if(n == 0 || n == 1){
        return true;
    }
   if(arr[0] > arr[1]){
    return false;
   }
   bool remainigpart = isSorted(arr+1, n-1);
   return remainigpart;
}

int main(){
    int n =0;
    cout <<" enter the array length: "<< endl;
    cin >> n;
    vector<int>arr(n);
    cout<< "enter the array element: "<< endl;
    for(int i =0; i < n; i++){
        cin >> arr[i];
    }
    if(isSorted(arr.data(), n)){
        cout<<"array is sorted" << endl;
    }else{
        cout << "array is not sorted "<< endl;
    }
        if(isSorted(arr.data(), n)){
        cout<<"array is sorted" << endl;
    }else{
        cout << "array is not sorted "<< endl;
    }
    return 0;
}