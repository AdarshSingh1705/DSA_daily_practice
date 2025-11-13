#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i< 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public: 
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }
 
        void insertUtil(TrieNode* root, string word){
            // base case
           if(word.length() == 0){
            root-> isTerminal = true;
            return;
           }
            
           int index = word[0] -'a';
           TrieNode* child;
           
           // present
           if(root -> children[index] != NULL){
            child = root-> children[index];
           }

           // absent
           else{
            child = new TrieNode(word[0]);
            root -> children[index] = child;
           }

           // recurssion
           insertUtil(child, word.substr(1));
        
        }

        void insertword(string word){
            insertUtil(root, word);
        }

    void printSuggestion(TrieNode* curr, vector<string>&temp, string prefix){
        if(curr -> isTerminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
                                        TrieNode* next = curr -> children[ch - 'a'];

            if(next != nullptr){
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }


      vector<vector<string> > getSuggestion(string str){
            TrieNode* prev = root;
            vector<vector<string> > output;
            string prefix = "";

            for(int i=0; i < str.length(); i++){
                char lastch = str[i];
                prefix.push_back(lastch);

                // check for last char
                TrieNode* curr = prev -> children[lastch - 'a'];

                if(curr == NULL){
                    break;
                }

                vector<string> temp;
                printSuggestion(curr, temp, prefix);

                output.push_back(temp);
                temp.clear();
                prev = curr;
            }
            return output;
        }
};

vector<vector<string>> phoneDir(vector<string>& contactList, string &queryStr){
    Trie *t = new Trie();

    for(int i=0; i<contactList.size(); i++){
        string str = contactList[i];
        t-> insertword(str);
    }

    // return ans
    return t -> getSuggestion(queryStr);
}

int main() {
    vector<string> contactList = {
        "alice", "bob", "carol", "dave", "diana", "daniel", "alex", "albert"
    };

    string queryStr = "da";

    vector<vector<string>> suggestions = phoneDir(contactList, queryStr);   

    cout << "Suggestions for each prefix of \"" << queryStr << "\":" << endl;
    for (int i = 0; i < suggestions.size(); i++) {
        cout << queryStr.substr(0, i + 1) << " → ";
        if (suggestions[i].empty()) {
            cout << "No suggestions";
        } else {
            for (const string& name : suggestions[i]) {
                cout << name << " ";
            }
        }
        cout << endl;
    }

    return 0;
}