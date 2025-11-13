#include<iostream>
#include<vector>
#include<string>
using namespace std;

string reverseStr(string& str, int i){
    int n = str.length();
    if(i == n-i-1){
        return str;
    }
    swap(str[i], str[n-i-1]);
    i++;
    return reverseStr(str, i);
}

int main(){
    string str1;
    cout <<  "Enter the string " << endl;
    cin >> str1;
    cout << "Reversed String is: " << reverseStr(str1, 0) << endl;
    
    return 0;
}
