#include<iostream>
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

    //empty list
        if(tail == NULL){
            Node* newNode = new Node(data);
            tail = newNode;
            newNode -> next = newNode;
        }

        // non-empty list
        else{
            Node* curr = tail;
            
            while (curr -> data != element){
                curr   = curr->next;
            }

            //element if found -> curr is representing wala node
            Node* temp = new Node(data);
            temp ->next = curr->next;
            curr -> next = temp;

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

void deletingNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
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

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    deletingNode(tail, 5);
    print(tail);

    if(isCircularList(tail)) {
        cout<< "his is Circular List: " << endl;
    }else{
        cout << "This is Not isCircularList" << endl;
    }
    
    return 0;

}