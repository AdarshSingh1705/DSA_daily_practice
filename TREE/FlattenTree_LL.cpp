#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this -> data = val;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};


class Solution{
public:
void  FlattenTree(Node* &root){

    if(root == nullptr) return ;

        Node* curr = root;

        while(curr != nullptr){
            if(curr -> left){

                Node* prev = curr -> left;

                while(prev -> right){
                    prev = prev -> right;
                }

                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = nullptr;
            }

            curr = curr -> right;
        }
    }

    Node* insert(Node* root, char val) {
        if (!root) return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

};

int main(){

    int n;
     cin >> n;

    Solution sol;
    Node* root = nullptr;
    for(int i=0; i < n; i++){
        int val;
        cin >> val;
        root = sol.insert(root, val);
    }

    sol.FlattenTree(root);

    while(root != nullptr){
        cout << root-> data <<" ";
        root = root -> right;
    }

    return 0;
}

