#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* random;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
            this -> random = NULL;
        }
};

void insertAtTail(Node* &cloneHead, Node* &cloneTail, int val){

    Node* newNode = new Node(val);
    if(cloneHead == NULL){
        cloneHead = newNode;
        cloneTail = newNode;
    }
    else{
        cloneTail -> next= newNode;
        cloneTail =  newNode;
    }

}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
}

void CloneList(Node* &head){
    
    Node* temp = head;
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    // step 1: create a  clone list
    while(temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }

    // step 2: Insert nodes if clone node in between original list

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(cloneNode != NULL && originalNode != NULL){
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode ;
         originalNode = next;
    
        next = cloneNode -> next;
        cloneNode -> next =  originalNode;
        cloneNode = next;   
    }

    // Step 3: Random pointer copy

    //originalNode = head;
    // cloneNode = cloneHead;
    // while( originalNode != NULL && cloneNode != NULL){
        
    //     if(originalNode  -> random != NULL){
    //         cloneNode -> random = originalNode -> random -> next;
    //     }
    //     else{
    //         cloneNode -> random = NULL;
    //     }

    //     cloneNode = cloneNode -> next;
    //     originalNode = originalNode -> next;

    // }

    temp =  head;
    while( temp != NULL){
        if(temp -> next != NULL){
            if(temp -> random != NULL){
                temp -> next -> random = temp -> random -> next;
            }
            else{
                temp->next->random = NULL;
            }
        }
        temp = temp -> next -> next;

    }

    // Step 4: Revert  the chaneges of step 2

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){

        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;

        if(originalNode != NULL){
             cloneNode -> next = originalNode -> next;
        }
        cloneNode = cloneNode -> next;
    }

    // step 5: return ans 
    // return head;
    head = cloneHead;
 
}

int main(){
    vector<int> values = {10, 20, 50, 40, 60, 90, 70};
    Node* head = new Node(values[0]);
    Node* curr = head;

    for(int i=1; i<values.size(); i++){
        curr -> next  = new Node(values[i]);
        curr = curr -> next;
    }
    print (head);
    CloneList(head);
    print (head);

    return 0;
}