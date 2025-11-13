
#include<iostream>
using namespace std;

int main(){
    int a = 0;
    int b = 1;
    int c;
    int n;
    cout << "Enter the length of the Fibonacci series: " << endl;
    cin >> n;

    if(n >= 1) {
        cout << a << " ";
    }
    if(n >= 2) {
        cout << b << " ";
    }

    for(int i = 2; i < n; i++){
        c = a + b;
        a = b;
        b = c;
        cout << c << " ";
    }

    return 0;
}