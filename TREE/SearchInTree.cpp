#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this -> data = data;
            this -> left = nullptr;
            this -> right = nullptr;
        }

        ~Node(){
            delete left;
            delete right;
            cout << " Deleting the element : " << data << endl;
        }

};

bool searchVal(Node* root, int val){

    if(root == nullptr){
        return false;
    }

    if(root -> data == val){
        return true;
    }
    
    return searchVal(root -> left, val) || searchVal(root -> right, val);

}

int main(){
    Node* root = new Node(10);
    root -> left = new Node(8);
    root -> right = new Node(12);
    root -> left -> right = new Node(9);
    root -> left -> left = new Node(7);
    root -> left -> left -> left = new Node(5);
    root -> right -> left =  new Node(11);
    root -> right -> right =  new Node(15);
    root -> right -> right -> right = new Node(20);

    if(searchVal(root, 7))
        cout << "TRUE" << endl;
    else    cout << "FALSE" << endl;

    delete root;

    return 0;
}