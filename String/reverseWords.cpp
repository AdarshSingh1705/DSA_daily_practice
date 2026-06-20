#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string reverseWords(string s){

  reverse(s.begin(), s.end()); // reverse whoel string
  int start = 0;

  for(int i=0; i<s.size(); i++){
    if(s[i] == s.size() || s[i] == ' ' ){
      reverse(s.begin() + start, s.begin()+i);
      start = i + 1;
    }
  }
  return s;
}

int main(){

  string s;
  getline(cin, s);
  
  cout<< reverseWords(s);

  return 0;
}