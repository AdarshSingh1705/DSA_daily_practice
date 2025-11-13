#include<iostream>
using namespace std;

struct Node{
    public:
        char data;
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

Node* insert(Node* root, char val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Find minimum in a subtree
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Delete from BST
Node* deleteNode(Node* root, char key) {
    if (!root) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: no child
        if (!root->left && !root->right)
            return NULL;

        // Case 2: one child
        else if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;

        // Case 3: two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Postorder Traversal
void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void preOrder(Node* root ){
    if( root == nullptr) return;
    cout << root -> data<< " ";
    preOrder(root -> left);
    preOrder(root -> right);
}
void inOrder(Node* root){
    
    if(root == nullptr) return;

    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);

}


int main(){
    int n;
    cout << "Enter the size  ";
    cin >> n;

    Node* root = nullptr;
    cout << "Enter elements: " << endl;
    for(int i =0; i < n; i++){
        char val;
        cin >> val;
        root = insert(root , val);
    }

    char del;
    cout << "Delete: ";
    cin >> del;
    root = deleteNode(root , del);

    cout << " Post Order Traversal:  ";
    postOrder(root);
    cout << endl << "Pre- Order Traversal:  ";
    preOrder(root);
    cout << endl << "In_order Traversal:  ";
    inOrder(root);
    cout << endl;

    return 0;
}
