#include<iostream>
using namespace std;

class TwoStack{
    private:
        int* arr;
        int size;
        int top1, top2;

    public:

    TwoStack(int n){
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    // Push to Stack1
    void push1(int x) {
        if (top1 + 1 < top2) {
            arr[++top1] = x;
        } else {
            cout << "Stack Overflow in Stack1\n";
        }
    }

    // Push to Stack2
    void push2(int x) {
        if (top1 + 1 < top2) {
            arr[--top2] = x;
        } else {
            cout << "Stack Overflow in Stack2\n";
        }
    }

    // Pop from Stack1
    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            cout << "Stack Underflow in Stack1\n";
            return -1;
        }
    }

    // Pop from Stack2
    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            cout << "Stack Underflow in Stack2\n";
            return -1;
        }
    }

    // Destructor
    ~TwoStack() {
        delete[] arr;
    }

};

int main(){
    TwoStack st(10);

    st.push1(5);
    st.push2(10);
    st.push1(15);

    cout <<  st.pop1() << endl; // 15
    cout << st.pop2() << endl; // 10
}