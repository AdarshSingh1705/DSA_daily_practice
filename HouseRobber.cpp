#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int findMax(vector<int> nums, int n){
    int prevInc = 0;
    int prevExc = 0;
    for(int num : nums){
        int temp = max(prevInc, prevExc + num);
        prevExc = prevInc;
        prevInc = temp;
    }
    return prevInc;
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        int t =0;
        cin >> t;
        nums[i] = t;
    }
    int ans = findMax(nums, n);
    cout << ans;
    return 0;
}