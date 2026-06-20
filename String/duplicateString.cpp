#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){

  string s;
  cout<<"Enter strings" << endl;
  cin>>s;

  unordered_map<char, int> freq;
  for(char c : s){
    freq[c]++;
  }

  for(auto i : freq){
    if(i.second > 1){
      cout<< "[ " << i.first << ", " << i.second << " ], ";
    }
  }

  return 0;
}