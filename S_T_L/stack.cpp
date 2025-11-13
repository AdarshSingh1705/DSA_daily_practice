#include<iostream>
#include<stack>

using namespace std;
int main(){
    stack<string> s; // stack of strings
    // stack<int> s; // stack of integers
   
    s.push("adarsh");
    s.push("singh"); // push 10 onto the stack
    // s.push(20);
    // s.push(30);
      s.push("kumar");

      cout<< "top element: "<<s.top()<<endl;

      s.pop();
      cout<< "top element after pop: "<<s.top()<<endl;

    cout << "Size of stack: " << s.size() << endl;

    cout<<"Empty or not: "<<s.empty()<<endl;

   return 0;
}
