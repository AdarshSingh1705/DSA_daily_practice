#include<iostream>
using namespace std;


int main(){
    int arr[]={2,3,4,5,6,7,8,9};
    int arr2[]={9,5,2,11,24,62,41,54};
    cout<<"intersection of a & b is:"<< endl;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(arr[i]==arr2[j]){
                cout<<arr2[j]<<' ';
            }
        }
    }

    return 0;
}