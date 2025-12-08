#include<iostream>
#include<vector>
using namespace std;  

class Node{
    public:
        int data;
        Node* next;

        // constructor
        Node(int data){
            this-> data = data;
            this -> next = NULL;
        }

};

void print(Node* &head){

    if(head == NULL || head-> next == NULL){
        cout << head -> data << endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<< endl;
}

void GetMiddle(Node* &head){

    if(head == NULL || head -> next == NULL){
        cout << head -> data << endl;
        return;
    }
     int len = 0;
     Node* temp = head;
     while(temp != NULL){
        len++;
        temp = temp -> next;
     }
     len = len /2;
     int n = 0;
     int d = 0;
     temp = head;
     while(n < len){
        temp = temp -> next;
        n++;
        d = temp -> data;
     }
     cout << d << endl;

}

int main(){
    Node* head = new Node(10);
    head ->next = new Node(20);
    head ->next ->next = new  Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = new Node(50);

    print(head);
    GetMiddle(head);

    return 0;
}