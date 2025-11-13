#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int> &ans, int n, int i) {
    int largest = i;         // Initialize largest as root
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    // If left child is larger than root
    if (left < n && ans[left] > ans[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && ans[right] > ans[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(ans[i], ans[largest]);
        heapify(ans, n, largest); // Recursively heapify the affected subtree
    }
}



int main(){

    vector<int> arr= {54, 53, 55, 52, 50};
    vector<int> arr1 = {54, 53, 55, 52, 50};

    // step 1: Merge both the arrays into one
        vector<int> ans;

        for(auto i : arr ){
            ans.push_back(i);
        }
        for(auto i: arr1){
            ans.push_back(i);
        }

    //step 2: build heap using merged array
        int n = ans.size();
        for(int i = n/2 - 1; i >=0; i--){
            heapify(ans, n, i);
        }

        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }

    return 0;
}