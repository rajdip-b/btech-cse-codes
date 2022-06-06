#include <iostream>
using namespace std;

void merge(int *arr, int l, int m, int r) {
    int leftArrSize = m-l+1;
    int rightArrSize = r-m;
    int *leftArr = new int[leftArrSize];
    int *rightArr = new int[rightArrSize];

    for (int x=0; x<leftArrSize; x++) {
        leftArr[x] = arr[l+x];
    }
    for (int y=0; y<rightArrSize; y++){
        rightArr[y] = arr[m+1+y];
    }

    int i=0,j=0,k=l;

    while (i<leftArrSize && j<rightArrSize) {
        if (leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i<leftArrSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j<rightArrSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int l, int r) {
    if (l<r) {
        int m = l + (r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void display(int *arr, int size) {
    for(int x=0;x<size;x++)
        cout<<arr[x]<<" ";
    cout<<endl;
}

int main() {
    int size;
    cin>>size;
    int *arr = new int[size];
    for(int x=0;x<size;x++)
        cin>>arr[x];
    cout<<"Array before sorting: ";
    display(arr,size);
    merge_sort(arr, 0, size-1);
    cout<<"Array after sorting: ";
    display(arr,size);
    return 0;
}