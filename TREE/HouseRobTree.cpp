#include<iostream>
#include<vector>
using namespace std;

struct Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node( int data){
        this -> data = data;
        this -> left = nullptr;
        this -> right = nullptr;
    }

    ~Node(){
        delete left;
        delete right;
    }
};
    pair<int, int> dfs(Node* root) {
        if (!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int rob = root-> data + left.second + right.second;

        int notRob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, notRob};
    }

    int rob(Node* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }


int main(){

    Node* root = new Node(5);
    root -> left = new Node(3);
    root -> left -> left = new Node(1);
    root -> right = new Node(10);
    root -> left -> right = new Node(4);
    root -> left -> right -> left = new Node(7);
    root -> right -> left =  new Node(6);
    root -> right -> right =  new Node(20);
    root -> right -> left -> right = new Node(8);

    cout << rob(root);

    return 0;
}