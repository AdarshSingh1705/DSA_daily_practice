#include<iostream>
using namespace std;
 
 int main() {
    char ch ;
    cout << "enter any number or charecter" << endl;

    cin>>ch;
    
    if(ch>='a'&&ch<='z')
     {
        cout<<"Lower case";
     }
    else if(ch>='A'&&ch<='Z')
     {
        cout<<"upper case";
     }
    else if(ch >= 0)
     {
        cout<< "numeric";
     }
else{
   cout<<"ero";
}
    return 0;

    }