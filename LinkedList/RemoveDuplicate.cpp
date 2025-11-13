#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
    //constructor
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

void removeDuplicate(Node* &head){
        if (!head) return;

    unordered_set<int> seen;
    Node* temp = head;
    Node* prev = nullptr;

    while(temp != nullptr){

        if(seen.count(temp->data)){
                Node* newNode = temp;
                temp = temp -> next;
                if(prev) 
                    prev -> next = temp;
                else
                    head = temp;
                newNode -> next =  nullptr;
                delete newNode;
        }
        else{ 
            seen.insert(temp -> data);
            prev = temp;
            temp = temp -> next;
        }
    }                
}

void print (Node * head ){

    if(head == NULL){
            cout << "List is empty! "<< endl;
            return;
    }
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

void freeList(Node*& head) {
    Node* curr = head;
    while (curr) {
        Node* nxt = curr->next;
        curr->next = nullptr;
        delete curr;
        curr = nxt;
    }
    head = nullptr;
}

int main(){
    vector<int> values = {10, 20, 30, 10, 10, 10, 30, 20, 40};
    Node* head = new Node(values[0]);
    Node* curr = head;

    for(int  i= 1; i < values.size(); i++){
            curr -> next = new Node(values[i]);
            curr = curr -> next;
    }
    cout << endl << "Before removing duplicate: " << endl; 
    print(head);

    removeDuplicate(head);
    cout << "After removing duplicate: "<< endl;
    print(head);


        freeList(head); // clean up
        return 0;
}