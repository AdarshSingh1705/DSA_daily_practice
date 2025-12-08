<<<<<<< HEAD
#include<iostream>
using namespace std;

void counting(int arr[], int n){
    int count0 =0;
    int count1 =0;
    int count2 =0;
    int i=0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            count0++;
        }
        else if(arr[i]==1){
            count1++;
        }
        else if(arr[i]==2){
            count2++;
        }
    } 
    cout<<"Printing sorted 0's, 1's & 2's" << endl;
       
        while(i <count0){
            cout<<"0"<<" ";
            i++;
        }
         i=0;
        while( i<count1){
            cout<<"1"<<" ";
              i++;      
        }
        i=0;
        while( i<count2 ){
            cout<<"2"<<" ";
            i++;
        }
    }
int main(){

    int arr[]={2,1,1,0,0,2,0,2,1,0,2,0,1,2,1,0,2,1,0,2,1};
     int n=21;
     counting(arr, 21);
     return 0;
=======
#include<iostream>
using namespace std;

void counting(int arr[], int n){
    int count0 =0;
    int count1 =0;
    int count2 =0;
    int i=0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            count0++;
        }
        else if(arr[i]==1){
            count1++;
        }
        else if(arr[i]==2){
            count2++;
        }
    } 
    cout<<"Printing sorted 0's, 1's & 2's" << endl;
       
        while(i <count0){
            cout<<"0"<<" ";
            i++;
        }
         i=0;
        while( i<count1){
            cout<<"1"<<" ";
              i++;      
        }
        i=0;
        while( i<count2 ){
            cout<<"2"<<" ";
            i++;
        }
    }
int main(){

    int arr[]={2,1,1,0,0,2,0,2,1,0,2,0,1,2,1,0,2,1,0,2,1};
     int n=21;
     counting(arr, 21);
     return 0;
>>>>>>> 0aeb97f3a68c61b23cdc45085f5163f4cadaef77
}