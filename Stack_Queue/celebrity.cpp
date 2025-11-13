#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
private:
        bool knows(vector<vector<int>> &M, int a, int b){
            if(M[a][b] ==1)
                return true;
            else
                return false;
        }

public: 
    int celebrity(vector<vector<int>> &M, int n){

        stack<int> s;
        for(int i =0; i < n; i++){
             s.push(i);

             while (s.size() != 1){
                
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                if(knows(M, a, b)){
                    s.push(b);
                }
                else{
                    s.push(a);
                }
             }
        }

        int ans = s.top();
        int ZeroCnt =0;
        int OneCnt = 0;

        for(int i =0; i < n; i++){
            
            if(M[ans][i] == 0)  ZeroCnt++;
            if(M[i][ans] == 1)  OneCnt++;
        }

        if(OneCnt != n-1 || ZeroCnt != n){
            return -1;
        }

        return ans;
    }

};

int main(){
    int n;
    cin >>n;
    vector<vector<int>> M(n, vector<int>(n,0));
    for(int i = 0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> M[i][j]; 
        }
    }
Solution ob;
cout << ob.celebrity(M, n) << endl;

return 0;
}