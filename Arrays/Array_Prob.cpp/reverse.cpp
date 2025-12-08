#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> & arr, int size){
    int left = 0, right = size-1;

    while(left < right){
        int temp = arr[right];
        arr[right] = arr[left];
        arr[left] = temp;
        left++;
        right--;
    }
}

void print(vector<int> arr, int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
   vector<int> arr;
   int n;
   cout << "Enter the size of array: ";
   cin >> n;
   
   cout << "Enter the value of array: ";
   for(int i=0; i<n; i++){
        int val;
        cin >> val;
        arr.push_back(val);
   }
   cout << "array before reversing: "<< endl;
   print(arr, n);
   reverseArray(arr, n);
   cout << "Array after reversing : "<< endl;
   print(arr, n);

   return 0;
}