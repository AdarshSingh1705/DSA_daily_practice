#include<iostream>
using namespace std;

int main(){
    
    // int i = 5;
    // // int *q = &i;
    // // cout<< q << endl;
    // // cout<< *q << endl;

    // // int *p = 0;
    // // p = & i;
    // // cout<< p <<endl;
    // // cout << *p <<endl; //These "q" and "p" will have the same the loction because 
    //                     // both of them are point to the same addres of the operator/ value.
    
    // int arr[10]; // 40 bytes of memory is allocated to the arr 

    // cout<< arr<< endl;
    // cout << &arr[0] << endl;
    // cout << *arr << endl;  // if tthe value is not given in the array then it will give some random value else this will give value of 1st array arr[0];
    // cout << *arr + 1 << endl; // this do the same but garbage value at 2nd position
    
    // arr[0] = {2};
    // arr[1] = {4};

    // cout << *arr << endl; // value at index zero = 2
    // cout << *arr + 1 << endl; // this will add 1 to the value at zero index ( 2 + 1 = 3);
    // cout << *(arr + 1) << endl; // value of the first index
    
    int temp[10];
    int *ptr = &temp[0];
    // int **p = *ptr; yeah wrong hai.
    cout << sizeof(temp) << endl;
    cout << sizeof(ptr) << endl;
    
    return 0;
}