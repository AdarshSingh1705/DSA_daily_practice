#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//- Slightly slower due to extra overhead in dynamic memory management.
// - If simplicity and safety matter → Use the vector-based approach.


// inv_count for count inversion Question. 

int merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArray(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArray(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    int inv_count = 0;

    while (i < leftArray.size() && j < rightArray.size()) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k++] = leftArray[i++];
        } else {
            arr[k++] = rightArray[j++];
            inv_count += (leftArray.size() - i); // key fix
        }
    }

    while (i < leftArray.size()) {
        arr[k++] = leftArray[i++];
    }

    while (j < rightArray.size()) {
        arr[k++] = rightArray[j++];
    }

    return inv_count;
}

int mergesort(vector<int>& arr, int left, int right) {
    int inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergesort(arr, left, mid);
        inv_count += mergesort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}

int main() {
    vector<int> arr = {3, 5, 4, 9, 1, 11, 45, 33, 22, 45};
    int count = mergesort(arr, 0, arr.size() - 1);

    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\nInversion Count: " << count << endl;

    return 0;
}


//Love Babbar code
// Faster for large inputs due to manual memory management.
//- If performance and efficiency matter (especially for large datasets) → Use the pointer-based approach.



// void merge(int *arr, int s, int e){

//     int mid = (e+s)/2;
//     int len1 = mid - s + 1;
//     int len2 = e - mid;

//     int *first = new int[len1];
//     int *second= new int[len2];

//     int mainArrayIndex = s;
//     for(int i =0; i < len1; i++){
//         first[i] = arr[mainArrayIndex++];
//     }

//     mainArrayIndex = mid+1;
//     for(int i=0; i<len2; i++){
//         second[i] = arr[mainArrayIndex++];
//     }

//     int index1 =0;
//     int index2 =0;
//     mainArrayIndex = s;

//     while(index1 < len1 && index2 < len2 ){

//         if(first[index1] <= second[index2]){
//             arr[mainArrayIndex++] = first[index1++];
//         }
//         else{
//             arr[mainArrayIndex++] = second[index2++];
//         }
//     }

//     while(index1 < len1){
//         arr[mainArrayIndex++] = first[index1++];
//     }

//     while(index2 < len2){
//         arr[mainArrayIndex++] = second[index2++];
//     }

//     delete []first;
//     delete []second;

// }

// void mergesort(int *arr, int s, int e){

//     if(s >= e){
//         return;
//     }
    
//     int mid = s + (e -s)/2;
    
//     mergesort(arr, s, mid);

//     mergesort(arr, mid+1, e);

//     merge( arr, s, e);
    
// }