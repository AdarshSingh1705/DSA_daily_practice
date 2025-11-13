#include<iostream>
using namespace std;

class node{
public:   
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this-> left = NULL;
        this -> right = NULL;
    }

    ~node(){
        delete left;
        delete right;
    }
};

node* buildTree(node* root){
    cout <<" Enter the data: " << endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return nullptr;
    }
    
    cout << "Enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}

int Maxheight(node* root){
   
    if(root == nullptr) return 0;
    
    int leftH  = Maxheight(root -> left);
    int rightH = Maxheight(root -> right);

    int ans = max(leftH, rightH) + 1;

    return ans;
}


int main(){
//     node *root = nullptr;

//    // creating  a tree
//    root = buildTree(root);

    node* root = new node(5);
    root -> left = new node(3);
    root -> left -> left = new node(1);
    root -> right = new node(10);
    root -> left -> right = new node(4);
    root -> left -> right -> left = new node(7);
    root -> right -> left =  new node(6);
    root -> right -> right =  new node(20);
    root -> right -> left -> right = new node(8);

    int ans = Maxheight(root);
    cout << ans<< endl; 

    return 0;
}     