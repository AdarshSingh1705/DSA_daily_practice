#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this-> next = NULL;
        }

        ~Node(){
            int values = this->data;
            if(this-> next != NULL){
                delete next;
                this ->next = NULL;
            }
        }
};

void merge(Node* &Zero, Node* &One, Node* &Two, Node* &head) {
    Node* tail = NULL;

    if (Zero != NULL) {
        head = Zero;
        tail = Zero;
        while (tail->next != NULL) tail = tail->next;
        if (One != NULL) {
            tail->next = One;
            tail = One;
            while (tail->next != NULL) tail = tail->next;
        }
        if (Two != NULL) {
            tail->next = Two;
        }
    } else if (One != NULL) {
        head = One;
        tail = One;
        while (tail->next != NULL) tail = tail->next;
        if (Two != NULL) {
            tail->next = Two;
        }
    } else {
        head = Two;
    }
}
void  sortLL(Node* &head){
    
    Node* Zero_cnt = NULL;
    Node* One_cnt = NULL;
    Node* Two_cnt = NULL;
    Node* temp = head;
    Node* KeepHead = NULL;

    while(temp != NULL){

        if(temp -> data == 0 ){
                Zero_cnt -> data = temp -> data;
                Zero_cnt = Zero_cnt -> next;
                temp = temp-> next;
        }
       else if(temp -> data == 1){
            One_cnt -> data = temp -> data;
            One_cnt = One_cnt -> next;
            temp = temp-> next;
        }
        else{
            Two_cnt -> data = temp -> data;
            Two_cnt = Two_cnt -> next;
            temp = temp-> next;
        }

    }

    merge(Zero_cnt, One_cnt, Two_cnt, head);
    
    head = Zero_cnt;

}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<< endl;
}
int main(){
    vector<int> arr = {1, 0, 0, 2, 1, 2, 0, 2, 1, 2, 0};
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int  i=1; i < arr.size(); i++){
        curr-> next = new Node(arr[i]);
        curr = curr -> next;
    }
    cout << " Before sorting: ";
    print(head);

    sortLL(head);
    print(head);

    return 0;
}