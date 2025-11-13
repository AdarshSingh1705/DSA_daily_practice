#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
    }
};