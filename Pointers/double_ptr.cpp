#include<iostream>
using namespace std;

int main(){
    
    int i = 5;
    int* ptr1 = &i;
    int** ptr2 = &ptr1;

    cout<< endl << " Everything is running fine " << endl << endl;

    cout<< "printing Ptr1:  " << ptr1 << endl;
    cout << "printing &ptr1: "<< &ptr1 << endl;
    cout << "printing *ptr1: "<< *ptr1 << endl;    

    cout << "printing ptr2: " << ptr2 << endl;
    cout << "printing &ptr2: " << &ptr2 << endl;
    cout << "printing *ptr2: "<< *ptr2 << endl;

    cout << "printing i: " << i << endl;
    cout << "printing &i: " << &i << endl;
    cout << "printing **ptr2: " << **ptr2 << endl;

    return 0;
}