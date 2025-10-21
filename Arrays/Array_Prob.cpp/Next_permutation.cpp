#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution{
public:
    int nextpermutation(std::vector<int>& arr){
        int n = arr.size();
        int pivot = -1;
// find the pivot element
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] < arr[i+1]){
                pivot = i;
                break;
            }
        }
// no pivot element
        if(pivot == -1){
        //  int left = 0, right = n -1;
        //     while( left <= right){
        //         swap(arr[left], arr[right]);
        //     }
        // OR
        reverse(arr.begin(), arr.end());
        
        }
// eind the element greater than pivot
        for(int i = n-1; i >= pivot; i--){
            if(arr[pivot] < arr[i]){
                swap(arr[pivot], arr[i]);
                break;
            }
        }

        sort(arr.begin()+pivot + 1, arr.end()); 
        // we can also reverse and we will get same answer.       
    }
};

int main(){
    std::vector<int> arr;
    solution sol; // creating object of solution class
    
    cout<<"enter "<<endl;
    for (int i = 0; i < 5; i++ ) {
        cin >> arr[i];
    }
    cout << endl;

    sol.nextpermutation(arr); // call function using object
    
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}