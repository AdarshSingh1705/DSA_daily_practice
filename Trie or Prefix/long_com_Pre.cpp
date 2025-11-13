#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children;
        bool isTerminal;

        // constructor
        TrieNode(char ch){
            data = ch;
            for(int i=0; i < 26; i++){
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
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        Trie* child;

        //present 
        if(root -> children[index] != NULL){
            child = root-> children[index];
        }

        // absent
        if(root ->children[index] == NULL){
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }


        insertUtil(child, word.substr(1));
    } 

    void insertWord(string word){
        insertUtil(root, word);
    }
};


int main(){
    
}
