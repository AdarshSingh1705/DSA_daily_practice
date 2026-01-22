#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

void Average(int arr[] ){
        int n = sizeof(arr);
        int sum =0;
    for(int i =0;  i < n;  i++){
            sum += arr[i];
    }
    cout << sum/n << "%" << endl;
}
int main(){
    string Name;
    cout << "Enter your name:  ";
    cin >> Name;
    cout << endl;
    int n =0;

    cout << "Enter number of subject: " << endl;
    cin >> n ;
    cout<< endl;
    if( n == 0){
        cout << "Not possible to calculate average of null numbers"<< endl;
        return 0;
    }
    int *arr = new int[n];

    cout << "Enter your subject number's: "<< endl;
    for(int i=0; i < n; i++){
        cout << i <<" subject marks: ";
        cin >>  arr[i];
        cout << endl;
    }
    cout << "Average percentage of ";
    cout << Name << "  is:  ";
    Average(arr);

}
