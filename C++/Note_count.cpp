#include<iostream>
using namespace std;

int main(){

         int n;
         cout<<"ENter the amount:"<<endl;
         cin>>n;
         int a=0;
         switch( 1 ) {
            
            case 1:
                if(n>=500){
                    a = n / 500;
                    cout<<"500 notes required is:"<< a <<endl;
                    n = n % 500;
               }
    
            case 2: 
                if(n>=100){

                    a = n / 100;
                    cout<<"number of 100's notes required is:"<< a <<endl;
                    n = n % 100;
                }
            case 3:
                if(n>=50){
                    a= n/50;
                    cout<<"Number of 50's notes required is:"<< a<<endl;
                    n = n%50;
                }    
            case 4:
                 if(n>=20){
                    a=n/20;
                    cout<<"Number of 20's notes required is:"<<a<<endl;
                    n=n%20;
                 }
            case 5:
                 if(n>=10) {
                    a= n/10;
                    cout<<"Number of 10's notes required is:"<< a <<endl;
                    n =n %10;

                 }  

            case 6:
                   if(n>=5){
                    a= n/5;
                    cout<<"Number of the 5's notes required is: "<< a <<endl;
                    n = n%5;
                   }       


            case 7:
                 if(n>=1){
                    a= n/1;
                    cout<<"Number's of 1's notes required is :"<< a<<endl;
                    
                   }  
             }
     

       return 0;
 }