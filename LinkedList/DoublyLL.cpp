#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
    
    // constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // Destructor
    ~Node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data: " << val  << endl; 
    }
};

// Insert at Head 
void insertAtHead(Node* &head, Node* &tail, int data){
    //empty list
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }    
}

//Insert At Tail in Doubly Linked List
void insertAtTail(Node* &head, Node* &tail, int data){

    // empty list
    if(tail == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail= temp;
    }
}

//Insert at Any position in doubly Linked List
void insertAtPosition(Node* &head, Node* &tail, int position, int data){

    // for starting position
    if(position == 1){
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
        while(cnt < position-1){
                temp = temp -> next;
                cnt++;
        }
       
    //inserting at last position
    if(temp -> next == NULL){
        insertAtTail(head, tail, data);
        return;
    }    
        // insert at any position
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next->prev = nodeToInsert -> next;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

//Traversing a Linked List
void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

// find linked list length
int getLength(Node* head){

    Node* temp = head;
    int length = 0;

    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

// Deletion of node
void deleteNode(int position, Node* &head){

    // deleting first or starting node
    if(position == 1){
        Node* temp = head;
        temp -> next ->prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        // deleting any middle node
        Node* curr = head;
        Node* prev  =  NULL;
        int cnt = 1;

        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr ->next;
        curr -> next = NULL;

        delete curr;

    }
}

int main(){
    // Node* node1 = new Node (10);

    //Empty list case
    Node* head = NULL; // Node* head = node1;
    Node* tail = NULL; // Node* tail = node1;
   
    print(head);

    insertAtHead (head, tail, 12);
    print(head);

    insertAtHead (head, tail, 8);
    print(head);

    insertAtHead (head, tail, 6);
    print(head);

    insertAtTail (head, tail, 16);
    print(head);

    insertAtPosition (head, tail, 4, 14);
    print(head);

    insertAtPosition (head, tail, 6, 20);
    print(head);    

    deleteNode(3, head);
    cout << getLength (head)  << endl;
    return 0;
}