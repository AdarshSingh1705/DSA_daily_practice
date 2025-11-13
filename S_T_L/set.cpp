// Set
// all the elements are unique in the set, no element are repeated
//  they are immutable
// complexity of insert, count, erase, find is O(logn)  on average

#include<iostream>
#include<set>

using namespace std;

int main(){
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);

    for(auto i:s){
        cout<<i<<" ";
    }
   cout<<endl;

   set<int>::iterator it = s.begin();
   it++;
   cout<<*it<<endl;
    s.erase(s.begin());

        for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<" 10 is present or not "<<s.count(10)<<endl;

    set<int>::iterator itr = s.find(10);

    for(auto it=itr; it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

  return 0;
}