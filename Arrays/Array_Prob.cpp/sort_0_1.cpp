#include <iostream>
using namespace std;
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

void printArray(int arr[], int n){
    cout<<"sorted array is: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl;
}

void sorting(int arr[], int n){
      int low=0, high = n-1;
    while(low < high){
        if(arr[low]==0){
            low++;
        }
        else if(arr[high]==1){
            high--;
        }
        else if(arr[low]==1 && arr[high]==0){
            swap(arr[low], arr[high]);
            low++; 
            high--;
        }
        
    }
     
}

int main(){
    int arr[]={0,0,1,0,1,0,1,0,1,1,1,0,0,0};
    int n=14;
    cout<<"Array before sorting is: " <<endl;
    for (int i=0; i<14; i++){
        cout << arr[i]<<" ";
    }
    cout<<endl;
    
    sorting(arr, n);
    printArray(arr, n);
    return 0;
}