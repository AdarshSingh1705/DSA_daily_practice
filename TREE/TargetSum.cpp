// TArget Sum problem using DFS though
// Time Complexity = O(N^2)
// Space Complexity = O(nlogn)
#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node (int val){
    this-> data = val;
    this-> left = this-> right = nullptr;
  }  
};

int countPath(Node* root, int target){
  if(!root) return 0;

  int count =0;

  if(target == root -> data){
    count++;
  }

  count += countPath(root -> left, target - root -> data);

  count += countPath(root -> right, target - root -> data);

  return count;

}

int pathSum(Node* root, int target){
  if(!root) return 0;

  int count =0;

  count += countPath(root, target);

  count += pathSum(root-> left, target);
  count += pathSum(root -> right, target);

  return count;
}

int main(){
  Node* root = new Node(10);
  root -> left = new Node(5);
  root -> left -> right = new Node(2);
  root -> left -> right -> right = new Node(1);
  root -> left -> left = new Node(3);
  root -> left -> left -> left = new Node(3);
  root -> left -> left -> right = new Node(-2);
  root -> right = new Node(-3);
  root-> right -> right = new Node(11);
  
  cout << pathSum(root, 8) << endl;

  return 0;
}