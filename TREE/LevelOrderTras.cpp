#include<iostream>
#include<vector>
#include<queue>
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
            cout << "Deleting node for Element : " << data << endl;
        }
};

vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();
        vector<int>level;

        while(size--){
            Node* temp = q.front();
            q.pop();
            level.push_back(temp -> data);

            if(temp -> left != nullptr){
                q.push(temp -> left);
            }
            if(temp -> right != nullptr){
                q.push(temp -> right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}

// Another method for traversal
void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
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

    Node* root = new Node(5);
    root -> left = new Node(3);
    root -> left -> left = new Node(1);
    root -> right = new Node(10);
    root -> left -> right = new Node(4);
    root -> left -> right -> left = new Node(7);
    root -> right -> left =  new Node(6);
    root -> right -> right =  new Node(20);
    root -> right -> left -> right = new Node(8);

    vector<vector<int>> ans = levelOrder(root);
    cout << "level Order Traversal " << endl;
    for (const auto& level : ans) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }


    // level order traversal another method
    cout << "Level order traversal without using extra memory" << endl;
    levelOrderTraversal(root);

    delete root;
    return 0;
}