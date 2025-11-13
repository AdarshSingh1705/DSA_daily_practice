#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x){

    if(s.empty()){
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(temp);

}

void reverseStack(stack<int>& s){

    if(s.empty())  return;
    int top = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, top);

}

int main(){
    stack<int> s;
    vector<int> values = {10, 20, 30, 40, 50, 60};

    // for(int val : values){
    //     s.push(val);
    // }
     s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);


   reverseStack(s);

   while(!s.empty()){
    cout << s.top() << " " ;
    s.pop();
   }
   cout<< endl;

   return 0;
}