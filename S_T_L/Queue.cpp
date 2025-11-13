#include<iostream>
#include<queue>

using namespace std;
int main(){
    queue<int> q;
    q.push(1); // q.push("adarsh"); --> string is pushed
    q.push(2);
    q.push(3);

    cout << q.front() << endl; // prints 1
    q.pop();
    cout << q.front() << endl; // prints 2

    cout<<"size after pop "<<q.size()<<endl;
}