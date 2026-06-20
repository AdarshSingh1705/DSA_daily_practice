#include<bits/stdc++.h>
using namespace std;

int solveTabulation(int n, int x, int y, int z){

  vector<int> dp(n+1, -1);
  dp[0] = 0;

  for(int i=1; i<= n; i++){
    if(i-x >= 0 && dp[i-x] != -1){
      dp[i] = max(dp[i], dp[i-x]+1);
    }
    if(i-y >= 0 && dp[i-y] != -1){
      dp[i] = max(dp[i], dp[i-y] + 1);
    }
    if(i-z >= 0 && dp[i-z] != -1){
      dp[i] = max(dp[i], dp[i-z] +1);
    }
  }
return max(0, dp[n]);
}


int main(){

  int n;
  cin>>n;
  int x, y, z;
  cin>> x >> y >> z;

  int ans = solveTabulation(n, x, y, z);
  cout<< "Answer is: " << ans << endl;

  return 0;
}