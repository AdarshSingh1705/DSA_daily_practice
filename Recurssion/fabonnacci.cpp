// recursion to find fibonnccci number.
// TC: 2^n.
#include <iostream>
using namespace std;

int fibonnacci(int n){
    if(n== 0 || n == 1){
        return n;
    }
    int ans = fibonnacci(n-1) + fibonnacci(n-2);

    return ans;
}

int main(){
    int n;
    
    cout<< "enter the number.. " << endl;
    cin >> n;
    cout << endl;

    int ans = fibonnacci(n);
    cout << ans << endl;
}