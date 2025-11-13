#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        // constructor
        Node(int data){
            this ->data = data;
            this -> next = NULL;
        }
};


void InsertAtTail(Node* &tail, int data){
    
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail ->next;  // or tail = temp;
}

void InsertAtHead(Node* &head, int d){

    // new node create
    Node* temp = new Node(d);
    temp-> next = head;
    head = temp;
}

// Inserting at Any position's
void InsertAtPosition(Node* &tail, Node* &head, int position, int data){
    
        if(position <= 0){
        cout << "Invalid position!" << endl;
        return;
    }
    
    // inserting at starting
    if(position == 1){
        InsertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

   while( cnt < position -1  && temp->next != NULL){
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

Node* floydCircleDetection(Node* head){

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout << "Present at : " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;
}

Node* getStartingNode(Node* head){

    // if(head == NULL || head -> next == NULL){
    //     cout<< " There is no any cycle: " << endl;
    //     return;
    // }

    // Node* slow = head;
    // Node* fast = head;

    // while (slow != NULL && fast  != NULL){

    //     slow = slow -> next;
    //     fast = fast -> next ;
    //     if(fast != NULL){
    //         fast = fast -> next;
    //     }

    //     if(slow == fast){
    //         slow = head;
    //         while(slow != fast){
    //             slow = slow -> next;
    //             fast = fast -> next;
    //         }
    //     }
    //        return slow;
    // }   
    // return NULL;

    if(head == NULL) 
        return NULL;

    Node* intersection = floydCircleDetection(head);
    
    if(intersection == NULL){
        return NULL;
    }

    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;
}

// printing function
void print(Node* head){

    Node* temp = head;
    while ( temp != NULL){
        cout<< temp ->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
}

void removeCycle(  Node* head){

    if(head == NULL){
        return;
    } 

    Node* startOfLoop = getStartingNode(head);
    if(startOfLoop == NULL){
        return;
    }
    //   if(startOfLoop == NULL){
    //     return head;
    // }
    Node* temp = startOfLoop;

    while( temp -> next != startOfLoop){
        temp = temp -> next;
    }
    temp -> next = NULL;
    cout << "cycle is removed!" << endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* tail = node1;
    Node* head = node1;

   InsertAtTail(tail, 20);
   InsertAtTail(tail, 30);

   InsertAtPosition(tail, head, 3, 25);
    print(head);

    tail -> next = head -> next;
    cout << "head : " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    // Node* cycle = floydCircleDetection(head);

    if( floydCircleDetection(head) != NULL){
        cout<< "Cycle is present at: " <<   endl;
    }else{
        cout << "No cycle " << endl;
    }

    Node* loop =  getStartingNode(head);
    cout << "loop starting: " << loop -> data << endl;

    removeCycle(head);
    print (head);

    return 0;
}

// Space complexity : O(1);
// Time complexity: O(n);