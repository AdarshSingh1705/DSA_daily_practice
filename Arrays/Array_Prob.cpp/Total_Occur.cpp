<<<<<<< HEAD
#include<iostream>
#include<algorithm>
using namespace std;

void Occurance(int arr[], int  n, int x){
    int count = 0;
    for (int i = 0; i < n; i++){
        if(x == arr[i]){
            count++;
        }
    }
    cout << "Number of occurrences of " << x << " is: " << count << endl;
}

int main(){
    int arr[] = {2,3,1,6,4,9,1,5,2,6,6,8,1,6,8,6,1,6};
     int n = sizeof(arr)/sizeof(arr[0]);
     Occurance(arr, n, 2);   
    return 0;
=======
#include<iostream>
#include<algorithm>
using namespace std;

void Occurance(int arr[], int  n, int x){
    int count = 0;
    for (int i = 0; i < n; i++){
        if(x == arr[i]){
            count++;
        }
    }
    cout << "Number of occurrences of " << x << " is: " << count << endl;
}

int main(){
    int arr[] = {2,3,1,6,4,9,1,5,2,6,6,8,1,6,8,6,1,6};
     int n = sizeof(arr)/sizeof(arr[0]);
     Occurance(arr, n, 2);   
    return 0;
>>>>>>> 0aeb97f3a68c61b23cdc45085f5163f4cadaef77
}