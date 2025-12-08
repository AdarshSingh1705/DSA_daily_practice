#include<iostream>
using namespace std;

void printarray(int arr[],int size){
       for(int i=0;i<size; i++){
         cout<<arr[i]<< " ";
    }
}

void SwapAlt(int arr[], int size){
        cout<< "Array after swaping"<<endl;
       int i=0;
        for(int i=0; i<size; i+=2){
            if(i+1<size){

          swap(arr[i],arr[i+1]);
          
          }
        }
        printarray(arr , 6)  ;
}

int main(){

    int arr[6]={12,23,45,56,78,89};
     cout<<"Array before swaping"<< endl;
    for(int i=0; i<6; i++){
     cout<< arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}