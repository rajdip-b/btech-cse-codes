#include <iostream>

using namespace std;

void swap (int *arr, int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void maxHeapify(int arr[], int start, int size) {
    int largest = start;
    int left = start*2+1;
    int right = start*2+2;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != start){
        swap(arr, largest, start);
        maxHeapify(arr, largest, size);
    }
}

void heap_sort(int *arr, int size) {
    for (int x = size/2-1; x >= 0; x--)
        maxHeapify(arr, x, size);
    
    for (int x=size-1; x>0 ;x--){
        swap(arr, 0, x);
        maxHeapify(arr, 0, x);
    }
}

int main() {
    int arr[] = {22, 14, 31, 45, 11, 9};
    heap_sort(arr, 6);
    printArray(arr, 6);
}