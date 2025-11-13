#include<iostream>
#include<queue>

using namespace std;
int main(){

    //max heap
    priority_queue<int> max_heap;

    //min heap
    priority_queue<int, vector<int>, greater<int>> min_heap;

     max_heap.push(1);
     max_heap.push(2);
     max_heap.push(3);
     max_heap.push(4);
     max_heap.push(5);
     cout<<"size of max heap before any operation: "<<max_heap.size()<<endl;
     cout<<"top of max heap: "<<max_heap.top()<<endl;
     
     int n =max_heap.size();
     for(int i=0; i<n; i++){
        cout<<max_heap.top()<<" ";
        max_heap.pop();
     }
     cout<<endl;

     min_heap.push(1);
     min_heap.push(2);
     min_heap.push(3);
     min_heap.push(4);
     min_heap.push(5);
     cout<<"size of min heap before any operation: "<<min_heap.size()<<endl;
     cout<<"top of min heap: "<<min_heap.top()<<endl;

      int m=max_heap.size();
     for(int i=0; i<m; i++){
        cout<<min_heap.top()<<" ";
        min_heap.pop();
     }
     cout<<endl;
      
      cout<<"Empty or not: "<<min_heap.empty()<<endl;

    return 0;      
}