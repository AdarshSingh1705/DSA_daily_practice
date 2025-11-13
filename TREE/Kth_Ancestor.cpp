#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

Node* solve(Node* root, int &k, int node){
    if(root == nullptr) return nullptr;

    if(root -> data == node) return root;

    Node* leftAns = solve(root -> left, k, node);
    Node* rightAns = solve(root ->right, k, node);

    if(leftAns != nullptr && rightAns == nullptr){
        k--;
        if(k <=0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if(rightAns != nullptr && leftAns == nullptr){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return nullptr;
}

int kthAncestor(Node* root, int k, int node){
    Node* ans = solve(root, k, node);
    if(ans == nullptr || ans -> data == node)
        return -1;
    
    return ans -> data;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    int k;
    cin >> k;
    int node;
    cin >> node;
    cout << kthAncestor(root, k, node);
    
    return 0;
}
