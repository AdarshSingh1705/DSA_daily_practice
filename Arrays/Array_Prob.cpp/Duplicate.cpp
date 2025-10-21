#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int Duplicate(int arr[], int n){
      
       for(int i=0; i<n; i++){
          for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j]){
                return arr[j];
              }
            }
       }
        return -1;
}

int main(){
    int arr[]={2,3,4,5,6,7,8,2};
    int n=8;
    int alt = Duplicate(arr, 8);
        sort(arr, arr+n);

    cout<<"Duplicate no. is: "<< alt <<endl;
    return 0;
}