#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;


// void numberMapping(string digit, string output, int index, vector<string>& ans, string mapping[]){
    
//     if(index >= digit.length()){
//         ans.push_back(output);
//         return;
//     }
    
//     int number = digit[index] - '0';
//     string value = mapping[number];

//     for(int i=0; i<value.length(); i++){
//         output.push_back(value[i]);
//         numberMapping(digit, output, index, ans, mapping);
//         output.pop_back();
//     }
// }

// vector<string> letterCombinations(string digit){
//     vector<string> ans;

//     if(digit.length() == 0){
//         return ans;
//     }

//     string output;
//     int index = 0;

//     string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

//     numberMapping(digit, output, index, ans, mapping);
    
//     return ans;
// }

// int main(){
//     string digit = "23";
//     int n = digit.length();
//     cout<<endl;
//     vector<string> ans = letterCombinations(digit);

//     for(int i=0; i< ans.size(); i++){
//         cout<<ans[i]<<endl;
//     }
//     cout<<endl;
//     return 0; 
// }

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    vector<string> map = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> res = {""};

    for (char digit : digits) {
        vector<string> temp;
        string letters = map[digit - '0'];

        for (const string& prefix : res) {
            for (char ch : letters) {
                temp.push_back(prefix + ch);
            }
        }

        res = temp; // update result with new combinations
    }

    return res;
}

int main() {
    cout << "\033[32m[+] Access Granted\033[0m" << endl;
    cout << "\033[31m[-] Access Denied\033[0m" << endl;
    cout << "\033[33m[*] Scanning...\033[0m" << endl;

    string digits = "232";

    // ⏱️ Start timing
    auto start = high_resolution_clock::now();

    vector<string> combos = letterCombinations(digits);

    // ⏱️ End timing
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // 🖨️ Print combinations
    for (const string& s : combos) {
        cout << s << " ";
    }
    cout << endl;

    // ⏱️ Show time taken
    cout << "\033[36m[✓] Execution Time: " << duration.count() << " microseconds\033[0m" << endl;

    return 0;

}