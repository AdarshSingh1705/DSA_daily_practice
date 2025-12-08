<<<<<<< HEAD
#include <iostream>
#include<algorithm>
using namespace std;


void allduplicate(int arr[], int n){

        cout<<"All duplicate are: "<<endl;

    for(int i=0; i<n; i++){
     
            if(arr[i]==arr[i-1]){
             cout<< arr[i] <<" ";
            }
    }  
        
}

int main(){
    int arr[]={2,3,1,2,6,5,1,4,5};
    int n = 9; 
    sort(arr, arr+n); 
    allduplicate(arr, 9); 
    
    return 0;
=======
#include <iostream>
#include<algorithm>
using namespace std;


void allduplicate(int arr[], int n){

        cout<<"All duplicate are: "<<endl;

    for(int i=0; i<n; i++){
     
            if(arr[i]==arr[i-1]){
             cout<< arr[i] <<" ";
            }
    }  
        
}

int main(){
    int arr[]={2,3,1,2,6,5,1,4,5};
    int n = 9; 
    sort(arr, arr+n); 
    allduplicate(arr, 9); 
    
    return 0;
>>>>>>> 0aeb97f3a68c61b23cdc45085f5163f4cadaef77
}