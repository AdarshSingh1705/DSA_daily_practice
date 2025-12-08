#include <iostream>
using namespace std;

// Definition of singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Merge two sorted linked lists (iterative version)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;
    return dummy.next;
}

// Merge k sorted linked lists stored in a simple array
ListNode* mergeKLists(ListNode* lists[], int k) {
    if (k == 0) return NULL;

    ListNode* result = lists[0];
    for (int i = 1; i < k; ++i) {
        result = mergeTwoLists(result, lists[i]);
    }
    return result;
}

int main(){

  ListNode* list1 = new ListNode(1);
   list1 -> next = new ListNode(3);
   list1 -> next -> next = new ListNode(5);

  ListNode* list2 = new ListNode(2);
   list2 ->next = new ListNode(4);
   list1 -> next -> next = new ListNode(6);

  ListNode* mergedList = mergeTwoLists(list1, list2);

   
}