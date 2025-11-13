#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }

        //Destructor
        ~Node(){
            int value = this -> data;
            //memory free
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }

            cout<< "Memory is free for node with data :  "  << value << endl;
        }
};

void InsertAtHead(Node* &head, int d){

    // new node create
    Node* temp = new Node(d);
    temp-> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int data){
    
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail ->next;  // or tail = temp;
}

// Inserting at Any position's
void InsertAtPosition(Node* &tail, Node* &head, int position, int data){
    // inserting at starting
    if(position == 1){
        InsertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

   while( cnt < position -1){
        temp = temp->next;
        cnt++;
   }
   // inserting at last position
   if(temp -> next == NULL){
    InsertAtTail(tail, data);
    return;
   }
   
   // create a Node for data
   Node* nodeToInsert = new Node(data);

   nodeToInsert -> next = temp->next;
   temp ->next = nodeToInsert;

}


// Deletion
void deleteNode(int position, Node* &head){

    // First Node deletion
    if (position == 1){
        Node* temp = head;
        head = head-> next;
        temp ->next = NULL;
        delete temp; // memory realeasing because memory is dynamically allocated
    }
    
    // deleting any middle node or last last node.
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr ->next;
        curr -> next = NULL;
        delete curr;
    }
}

// printing function
void Print(Node* &head){

    Node* temp = head;
    while ( temp != NULL){
        cout<< temp ->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    InsertAtHead(head, 8);
     Print(head);

     InsertAtTail(tail, 15);
     InsertAtTail(tail, 20);
    Print(head);

     InsertAtPosition(tail, head, 5, 55);
     Print(head);

     deleteNode(1, head);
    Print(head);

    deleteNode(4, head);
    Print(head);
    return 0;
}