#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this ->data = data;
            this -> left = nullptr;
            this -> right = nullptr;
        }

        ~Node(){
            delete left;
            delete right;
            cout << "Deleting the Node of the data: " << data << endl; 
        }
};

void leftView(Node* root){
    cout << "LeftView: ";
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* curr = q.front();
            q.pop();
            if(i==0) cout << curr -> data <<", ";
            if(curr ->left) q.push(curr-> left);
            if(curr-> right) q.push(curr -> right);
        }
    }    cout << endl;
}

void rightView(Node* root){
    cout << "Rightview";
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* temp = q.front();
            q.pop();
            if(i == 0) cout << temp -> data<<", ";
            if(temp -> right) q.push(temp->right);
            if(temp -> left) q.push(temp->left);
        
        }
    }
    cout << endl;
}


void topView(Node* root) {
    if(root == nullptr) return;

    map<int, int>hdmap;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto front = q.front(); 
        q.pop();
        Node* node = front.first;
        int hd = front.second;

        if(hdmap.find(hd) == hdmap.end()){
            hdmap[hd] = node -> data;
        }
        if(node -> left) q.push({node -> left, hd -1});
        if(node -> right) q.push({node -> right, hd+1});
    }cout<< " Top: " ;
    for(auto i:hdmap){
        cout<< i.second << ", ";
    }cout<< endl;
}


void bottomView(Node* root){

    if(root == nullptr) return;

    map<int, int> topNode;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
       pair<Node*,int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        
        topNode[hd] = frontNode -> data;

        if(frontNode -> left)
            q.push(make_pair(frontNode -> left, hd-1));
        if(frontNode -> right)
            q.push(make_pair(frontNode -> right, hd+1));
    }cout<< " bottom: " ;
    for(auto i:topNode){
        cout<< i.second << ", ";
    }cout<< endl;
}


int main(){

    Node* root = new Node(5);
    root -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> left -> left = new Node(1);
    root -> left -> left -> right = new Node(2);
    root -> left -> left -> right -> left = new Node(12);
    root -> right = new Node(10);
    root -> right -> left =  new Node(6);
    root -> right -> right =  new Node(20);
    root -> right -> left -> right = new Node(8);

    leftView(root);
    rightView(root);
    topView(root);
    bottomView(root);


    return 0;
}