#include<iostream>
#include<climits>
using namespace std;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val) {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
}; 

bool isBST(BinaryTreeNode* root, int min, int max) {
    if (root == nullptr) {
        return true;
    }

    if (root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data - 1);  // strict inequality
        bool right = isBST(root->right, root->data + 1, max); // strict inequality
        return left && right;
    } else {
        return false;
    }
}

bool validateBST(BinaryTreeNode* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(10);
    root -> left = new BinaryTreeNode(8);
    root -> right = new BinaryTreeNode(12);
    root -> left -> right = new BinaryTreeNode(9);
    root -> left -> left = new BinaryTreeNode(7);
    root -> left -> left -> left = new BinaryTreeNode(5);
    root -> right -> left =  new BinaryTreeNode(11);
    root -> right -> right =  new BinaryTreeNode(15);
    root -> right -> right -> right = new BinaryTreeNode(20);

    if(validateBST(root)){
        cout << "This tree is bst: "<<endl;
    }else{
        cout << "this is not bst: "<< endl;
    }

    return 0;
}