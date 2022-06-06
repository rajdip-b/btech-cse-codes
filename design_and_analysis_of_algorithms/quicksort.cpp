#include <iostream>
using namespace std;

void swap (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for (int x=low;x<=high-1;x++) {
        if (arr[x] < pivot) {
            i+=1;
            swap(&arr[i], &arr[x]);
        }
    }
    i+=1;
    swap(&arr[i], &arr[high]);
    return i;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

void display_array(int *arr, int size) {
    for (int x=0;x<size;x++) {
        cout<<arr[x]<<" ";
    }
    cout<<endl;
}

int main() {
    int size, *arr;
    cin>>size;
    arr = new int(size);
    for (int x=0;x<size;x++){
        cin>>arr[x];
    }
    cout<<"Before sorting: ";
    display_array(arr,size);
    quick_sort(arr, 0, size-1);
    cout<<"After sorting: ";
    display_array(arr,size);
    return 0;
}