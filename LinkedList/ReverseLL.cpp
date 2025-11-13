#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    // Constructor
       Node(int data){
            this -> data = data;
            this -> next = NULL;
        }

};

void reverseLL(Node* &head){

    Node* curr = head;
    Node* prev = NULL;
    if(head == NULL || head-> next == NULL){
        cout << "No such number of elements to perform reverse." << endl;
        return;
    }

    while(curr != NULL){
        Node* newNode  =  curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = newNode;
    }
     head = prev;
}

void print(Node* &head){

    Node* temp = head;
    if(head == NULL){
        cout << "Nothing to print, this linked list is empty" << endl;
        return;
    }

    while( temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

// Node* head = new Node(10);
// head->next = new Node(20);
// head->next->next = new Node(30);
// head->next->next->next = new Node(40);

// OR
std::vector<int> values = {10, 20, 30, 40, 50};
Node* head = new Node(values[0]);
Node* current = head;
    print(head);
for (size_t i = 1; i < values.size(); ++i) {
    current->next = new Node(values[i]);
    current = current->next;
}

    print(head);

    reverseLL(head);
    print(head);

    return 0;
}