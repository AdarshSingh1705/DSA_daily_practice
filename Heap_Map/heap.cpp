#include <bits/stdc++.h>
using namespace std;
//
// Manual Max Heap Implementation
//
class MaxHeap {
    vector<int> heap;

    void heapifyDown(int i) {
        int left = 2*i + 1, right = 2*i + 2, largest = i;
        if (left < heap.size() && heap[left] > heap[largest]) largest = left;
        if (right < heap.size() && heap[right] > heap[largest]) largest = right;
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[(i-1)/2] < heap[i]) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }

    int top() { return heap[0]; }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }

    bool empty() { return heap.empty(); }
};

//
// Manual Min Heap Implementation
//
class MinHeap {
    vector<int> heap;

    void heapifyDown(int i) {
        int left = 2*i + 1, right = 2*i + 2, smallest = i;
        if (left < heap.size() && heap[left] < heap[smallest]) smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest]) smallest = right;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[(i-1)/2] > heap[i]) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }

    int top() { return heap[0]; }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }

    bool empty() { return heap.empty(); }
};

int main() {
    // --- Built-in Max Heap ---
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);
    cout << "Built-in Max Heap top: " << maxHeap.top() << endl; // 20

    // --- Built-in Min Heap ---
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);
    cout << "Built-in Min Heap top: " << minHeap.top() << endl; // 5

    // --- Manual Max Heap ---
    MaxHeap mh;
    mh.push(10);
    mh.push(5);
    mh.push(20);
    cout << "Manual Max Heap top: " << mh.top() << endl; // 20
    mh.pop();
    cout << "After pop, Manual Max Heap top: " << mh.top() << endl; // 10

    // --- Manual Min Heap ---
    MinHeap minh;
    minh.push(10);
    minh.push(5);
    minh.push(20);
    cout << "Manual Min Heap top: " << minh.top() << endl; // 5
    minh.pop();
    cout << "After pop, Manual Min Heap top: " << minh.top() << endl; // 10

    return 0;
}