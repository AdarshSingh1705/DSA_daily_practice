// no number of ways to cluimb to nth stairs using recurssion.

#include<iostream>
using namespace std;

int climbStairs(int n){

    if(n <= 0){
        return 0;
    }
    if (n == 1 || n == 2){
        return 1;
    }

    int ans = climbStairs(n -1) + climbStairs(n-2);
    return ans;
}

int main(){
    int n;
    cout << "Enter the number.. = " ;
    cin >> n;
    cout<< endl;

    cout << climbStairs(n) << endl;
    // cin >> n;
    // cout << climbStairs(n) << endl;
    // cin >> n;
    // cout << climbStairs(n) << endl;
    return 0;
}