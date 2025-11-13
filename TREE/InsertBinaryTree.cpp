#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
public: 
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this -> data = val;
        this -> left =  nullptr;
        this ->right = nullptr;
    }
};

TreeNode* insertBinaryTree(TreeNode* root, int data) {
        TreeNode* newNode = new TreeNode(data);

        // If tree is empty
        if (!root) return newNode;

        // Use queue for level order insertion
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            // Insert in the left child if empty
            if (!temp->left) {
                temp->left = newNode;
                return root;
            } else {
                q.push(temp->left);
            }

            // Insert in the right child if empty
            if (!temp->right) {
                temp->right = newNode;
                return root;
            } else {
                q.push(temp->right);
            }
        }
        return root;
}

//====================== LOT=========
void levelOrderTraversal(TreeNode* root){

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

    
int main(){
    int n;
    cin >> n;
    TreeNode* root = nullptr;

    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        root = insertBinaryTree(root, val);
    }
    cout<< endl << "level order traversal: "<< endl ;
    levelOrderTraversal(root);
    
    return 0;
}
