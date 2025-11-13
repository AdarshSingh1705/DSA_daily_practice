#include<iostream>
#include<string>

using namespace std;

bool ispalidrome(string& str1, int i){
    int n  = str1.length();
    if( i >= n-i-1){
        return true;
    }
    if(str1[i] != str1[n-i-1]){
        return false;
    }
    return ispalidrome(str1, i+1);

}

int main(){
    string str1;
    cout << " Enter the string:  ";
    cin >> str1;
    
    int n = str1.length();
    if(ispalidrome(str1, 0)){
        cout << "Entered string " << str1 << " is palidrome.. " << endl;
    }else{
        cout <<"entered string " << str1 << " is not a palidrome... " << endl;
    }
    return 0;
}