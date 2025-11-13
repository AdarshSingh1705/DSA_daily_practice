#include <iostream>
using namespace std;

class Node{
public:
   int data;
   Node* next;

   Node(int d) {
      int data = d;
      next = NULL;

   }

   

}

Node* merge(Node* list1, Node* list2){
   Node*    
}

int main(){

   Node* list1 = new Node(1);
   list1 -> next = new Node(3);
   list1 -> next -> next = new Node(5);

   Node* list2 = new Node(2);
   list2 ->next = new Node(4);
   lsit -> next -> next = new Node(6);

   Node* mergedList = merge(list1, list2);

   
}