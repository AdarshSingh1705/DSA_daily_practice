#include <stdio.h> 

int linearSearch(int arr[], int n, int key) { 
    for (int i = 0; i < n; i++) { 
        if (arr[i] == key) { 
            return i; // return index if found 
        } 
    } 
    return -1; // not found 
} 
int main() { 
    printf("Name - Adarsh Singh\nRoll No. - 2301920100020\n"); 
    int n; 
    printf("Enter size of array: "); 
    scanf("%d", &n); 
    int arr[n]; 
    printf("Enter elements: "); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
    int key; 
    printf("Enter element to search: "); 
    scanf("%d", &key); 
    int result = linearSearch(arr, n, key); 
    result != -1 ? printf("Element found at index %d\n", result) : printf("Element not found!\n"); 

    return 0; 
}