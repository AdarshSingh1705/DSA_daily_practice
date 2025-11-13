#include<iostream>
#include<map> 
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        //consturtor
        Node(int d){
            this -> data = d;
            this -> next = NULL;
        }

        //  destructor
        ~Node (){
            int value = this -> data;
            if(this -> next != NULL){
                delete next;
                next  = NULL;
            }
            cout << " Memory is free for the node with data: " << value << endl;
        }
};

void insertNode(Node* &tail, int element, int data){

    // Empty list
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        tail ->next = temp;
    }

    else{
        Node* curr = new  Node(data);

        while(tail -> data != element){
            tail = tail ->next;
        }
        
        curr ->next = tail -> next;
        tail -> next = curr;
    }
}

void print(Node* &tail){

    if(tail == NULL){
        cout<< "linked list is empty cannot print any thing! " << endl;
        return ;
    }

    Node* temp = tail;
    do{
        cout<< tail ->data <<" " ;
        tail  = tail->next;
    }while(tail != temp);
    cout << endl;

}

bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }

    map <Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL){

        //cycle is present
        if(visited[temp] == true){
            return true;
        }

        visited[temp] = true;
        temp  = temp ->next;
    }
     return false;
}

int main(){
    // Node* node1 = new Node(10);
    Node* tail = NULL; // EMPTY LIST
    
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    // insertNode(tail, 5, 7);
    // print(tail);

    // insertNode(tail, 7, 9);
    // print(tail);

    if(detectLoop(tail)){
        cout << "Linked List is Circular in nature " << endl;
    }else{
        cout << "Linked List is not Circular "<< endl;
    }

    return 0;
}