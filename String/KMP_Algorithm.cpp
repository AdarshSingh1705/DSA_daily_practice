#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> computelps(string pattern){
  
  int m = pattern.length();
  int len = 0, i = 1;
  vector<int> lps(m, 0);

  while (i < m)
  {
    if(pattern[i] == pattern[len]){
      len++;
      lps[i] = len;
      i++;
    }
    else{
      if(len != 0 ){
        len = lps[len - 1];
      }
      else{
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}

vector<int> searchPattern(string text, string pattern){
  int n = text.length();
  vector<int>result;
  int m = pattern.length();
  if(m == 0) return result;

  vector<int> lps = computelps(pattern);
  int i = 0, j = 0;
  while (i < n)
  {
    if(text[i] == pattern[j]){
      i++; j++;
    }
    if(j == m){
      result.push_back(i - j);
      j = lps[j - 1];
    }
    else if(i < n && text[i] != pattern[j]){
      if(j != 0) j = lps[j - 1];
      else i++; 
    }
  }
  return result;  
}

int main(){

  return 0;
}