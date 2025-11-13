#include <stdio.h>
#include<vector>
// Function to swap two elements
void swap(int* a, int* b) {    int temp = *a;   *a = *b;   *b = temp; }
// Partition function using Lomuto's partition scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
int i = low - 1;       // Index of smaller element
for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {  i++;
            swap(&arr[i], &arr[j]); }  }
    swap(&arr[i + 1], &arr[high]);
    return i + 1; }
// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  quickSort(arr, pi + 1, high);  }  }
// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int n;
    printf("Quick Sort\nName - Adarsh Singh\nRoll No. - 2301920100020\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    printArray(arr, n);
return 0;
}