#include<iostream>
#include<deque>
using namespace std;

int main(){
  
  deque<int> d;
  d.push_front(10);
  d.push_back(20);
  for(int i:d){
    cout<<i<<" ";
  }
  cout<<endl;

  // d.pop_front();
  // for(int i:d){
  //   cout<<i<<" ";
  // }

  cout<< "print first Index element: "<<d.at(0)<<endl;
  
  cout<<"print front element: "<<d.front()<<endl;
  cout<< "print last element: "<<d.back()<<endl;
  cout<< "print size of deque: "<<d.size()<<endl;
  cout<< "print empty: "<<d.empty()<<endl; // true '1' if empty, false '0' if not empty
    
   cout<<"before erase"<<d.size()<<endl; 
   d.erase(d.begin(),d.begin()+1);
   cout<<"after erase"<<d.size()<<endl;
   


  return 0;
}