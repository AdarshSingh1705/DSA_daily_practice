#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int  data){
            this -> data = data;
            this -> left = nullptr;
            this -> right = nullptr;
        }

        ~Node(){
            delete left;
            delete right;
            cout << "Deleting node for Element : " << data << endl;
        }
};

Node* insert( Node* root,  int val){
    if(root == nullptr) 
        return new Node(val);

    if(val < root -> data)
        root ->left = insert(root -> left , val);
    else 
        root -> right = insert(root -> right, val );

    return root;
}

void print(Node* root){
    if(root == nullptr)
        return;

        print(root -> left);
        cout << root -> data << " ";
        print(root -> right);
        
}

pair<int, int> diameterFast(Node* root){

    if (root == nullptr){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> leftH = diameterFast(root -> left);
    pair<int, int> rightH = diameterFast(root -> right);
    int op1 = leftH.first;
    int op2 = rightH.first;
    int op3 = leftH.second + rightH.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(leftH.second , rightH.second) + 1;

    return ans;

}

int diameter(Node* root){

    return diameterFast(root).first;
}

int main(){
    int size;
    cin >> size;

    Node* root = nullptr;
    for(int i =0; i < size; i++){
        int val;
        cin >> val;
        root = insert(root, val);
    }

    print(root);
    return 0;
}