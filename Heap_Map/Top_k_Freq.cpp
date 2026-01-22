// Top K Frequent Elements

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> topK(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int, int>count;
    for(int num : nums){
      count[num]++;
    }

    vector<vector<int>> bucket(n+1);
    for(auto& p: count){
      bucket[p.second].push_back(p.first);
    }
    vector<int>result;
    for(int i=n; i >=0; --i){
      for(auto& val : bucket[i]){
        result.push_back(val);
        if(result.size() == k){
          return result;
        }
      }
    }

    return result;
}

int main(){
  
    vector<int> nums = {1, 2, 3, 2, 1, 4, 2, 4, 2, 1, 3, 2, 1, 3};
    int k = 3;
    vector<int> ans = topK(nums, k);
    for(int i=0; i < k; i++){
      cout << ans[i] << " ";
    }

    return 0;
}