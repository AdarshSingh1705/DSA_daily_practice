#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node (int data){
            this -> data = data;
            this -> next = NULL;
        }

        ~Node(){
            int values = this -> data;
            if(this -> next != NULL){
                delete next;
                this -> next = NULL;
            }
        }
};

void reverseLL(Node* &head ){
        Node* curr = head;
        Node* prev  = NULL;

        while(curr != NULL){
            Node* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }cout << endl;
}

void addNodes(Node* &head1, Node* &head2){

        Node* curr1 = head1;
        Node* curr2 = head2;
        Node* prev = NULL;
        int carry = 0;

        while (curr1 != NULL || curr2 != NULL || carry > 0){

            int num1 = (curr1 != NULL) ? curr1->data : 0;
            int num2 = (curr2 != NULL) ? curr2->data : 0;

           int sum = num1 + num2 + carry ;
            carry = sum / 10;

            Node* newNode = new Node(sum %10);
            if (prev == NULL) {
                head1 = newNode; // First node in result list
            } else {
                prev->next = newNode;
            }
            prev = newNode;

            if(curr1 != NULL) {
                curr1 = curr1 -> next;
            }
            if(curr2 != NULL){
                curr2 = curr2 -> next;
            }
        }

}
int main(){
    vector<int> arr1 = {9, 2, 3};
    vector<int> arr2 = {2, 1, 9};  
    Node* head1 =  new Node(arr1[0]);
    Node* head2 =  new Node(arr2[0]);
    Node* curr1 = head1;
    Node* curr2 = head2;

    for(int i = 1; i < arr1.size(); i++){
        curr1 ->next = new Node(arr1[i]);
        curr1 = curr1 -> next;
    }

    for(int i = 1; i < arr2.size(); i++){
        curr2 ->next = new Node(arr2[i]);
        curr2 = curr2 -> next;
    }

    reverseLL(head1);
    reverseLL (head2);
cout << "after reversing the ll" << endl;
    print(head1);
    print(head2);
    
    addNodes(head1, head2);
    reverseLL(head1);
cout << "after adding nodes: " << endl;
    print (head1);

    return 0;
}