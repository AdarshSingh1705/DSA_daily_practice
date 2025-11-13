#include<iostream>
// #include<stack>
using namespace std;

class Stack {
 // Behaviour
    public:
        int *arr;
        int size;
        int top;

        Stack(int size){
            this -> size = size;
            arr = new int(size);
            top = -1;
        }

        void push(int element){
            if(size - top  > 1){
                top++;
                arr[top] = element;
            }else{
                cout << "Stack OverFlow! " << endl;
            }
        }

        void pop(){
            if(top >= 0){
                top--;
            }
            else{
                cout << " stack UnderFlow! " << endl;
            }
        }

        int peek(){
            if(top >= 0){
                return arr[top];
            }
            else{
                cout << "stack is empty! " << endl;
                return -1;
            }
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }   
            else{
                return false;
            }
        }

};


int main(){
    
    Stack st(5); // stack of size 5

        st.push(22);
        st.push(43);
        st.push(44);
        st.push(22);
        st.push(43);
        st.push(44);
        
        cout << st.peek() << endl;

        st.pop();
        cout << st.peek() << endl;

        if(st.isEmpty()){
            cout << " Stack is empty! " << endl;
        }else{
            cout << "stack is not empty! " << endl;
        }

        // Built in fucntion to create an Stack
/*
            stack<int> s;

            s.push(1);
            s.push(3);

            s.pop();
            cout << s.top() << endl;

            if(s.empty()){
                cout << "Stack is empty! " << endl;
            }else{
                cout << "Stack is not empty! " << endl;
            }

            cout << "size of stack is :" << s.size() << endl;

*/

        return 0;
}