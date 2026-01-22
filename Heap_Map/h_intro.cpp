#include<iostream>
#include<vector>
using namespace std;

class heap{
public:
    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<= size; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }

    void deletefromHeap(){
        if(size == 0) {
            cout <<"heap empty nothing to delete: " << endl;
            return;
        }
    // step 1: put last element into first index
        arr[1] = arr[size];

    // step 2: remove last element
        size--;

    // step 3: Take root node to it's correct position
        int i = 1;
        while(i < size){
            int leftindex = 2*i;
            int rightindex = 2*i + 1;

            if(leftindex < size && arr[i] < arr[leftindex]){
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if(rightindex < size && arr[i] < arr[rightindex]){
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else{
                return;
            }
        }
    }
};

// max heap
void Maxheapify(vector<int>& arr, int n, int i){
    
    int largest = i;
    int left = 2* i+1;
    int right = 2 * i +2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    } 

    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        Maxheapify(arr, n, largest);
    }
}

// min heap
void Minheapify(vector<int>&arr1, int n, int i){
    
    int smallest = i;
    int left = 2* i+1;
    int right = 2 * i +2;

    if(left < n && arr1[smallest] > arr1[left]){
        smallest = left;
    } 

    if(right < n && arr1[smallest] > arr1[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr1[smallest], arr1[i]);
        Minheapify(arr1, n, smallest);
    }
}

vector<int> buildMaxheap(vector<int> &arr){
    int n= arr.size();
    for(int i = n/2-1; i>=0; i--){
        Maxheapify(arr, n, i);
    }
}


vector<int> buildMinHeap(vector<int> &arr1){
    int n= arr1.size();
    for(int i = n/2-1; i>=0; i--){
        Minheapify(arr1, n, i);
    }
}


int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    h.deletefromHeap();
    h.print(); 
// 0 - based indexing
    vector<int> arr= {54, 53, 55, 52, 50};
    vector<int> arr1 = {54, 53, 55, 52, 50};

// building max heap
    buildMaxheap(arr);
    cout << "Printing max heap. " << endl;
    for(int i =0; i< 5; i++){
        cout<< arr[i] << " ";
    }cout << endl;
    
// building min heap
    buildMinHeap(arr1);

    cout << "Printing min heap. " << endl;
    for(int i =0; i< 5; i++){
        cout<< arr1[i] << " ";
    }cout << endl;

    return 0;
}