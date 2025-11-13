#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this-> data = data;
        this-> left = nullptr;
        this-> right = nullptr;
    }

    ~Node(){
        delete left;
        delete right;
        cout << "Deleting node: " << data << endl;
    }
};

// void printLeaf(Node* &root){

//     if(root ==  nullptr){
//         return;
//     }

//     if(root -> left == nullptr && root -> right == nullptr){
//         cout << root -> data<< " ";
//     } 

//     printLeaf(root->left);
//     printLeaf(root -> right);
// }

void printleaf(Node* root){
    if(root == nullptr) return;

    if(root -> left == nullptr && root -> right == nullptr){
        cout << root -> data << " ";
    }
}
int main(){
    Node* root = new Node(10);
    root -> left =  new  Node(8);
    root -> right =  new Node(12);
    root -> left -> left = new Node(5);
    root -> left -> right = new Node(7);
    root -> left -> left -> left = new Node(3); 
    root -> right -> right = new Node(15);
    root -> right -> left = new Node(11);
    root -> right -> right -> right = new Node(17);
    root -> right -> right -> right -> right =  new Node(20);
    
    printleaf(root);

    delete root;
    return 0;
}