// list is made from deque

#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l; // list of integers
    
    list<int> n(l); // copy the list l to n
    list<int> m(5,100); // list m with 5 elements, each element is 100
    for(int i:m){
        cout<<i<<" ";
    }
    cout<<endl;
    
    l.push_back(10);
    l.push_front(20);

    for(int i:l){
        cout<<i<<" ";
    }

    cout<< endl;
l.erase(l.begin());
cout<<"after erase"<< endl;
for(int i:l){
    cout<<i<<" ";
    }
        cout<<endl;
    cout<<" size if the list is: "<< l.size()<<endl;

}