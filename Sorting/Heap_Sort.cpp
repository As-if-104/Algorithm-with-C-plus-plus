#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[], int len, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if (left < len && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < len && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        Heapify(arr, len, largest);
    }
}

void HeapSort(int arr[], int len){
    for (int i = len/2-1; i >= 0; i--){
        Heapify(arr, len, i);
    }

    for (int i = len-1; i > 0; i--){
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

void PrintArray(int arr[], int len){
    for (int i = 0; i < len; i++){
        cout << " " << arr[i];
    }
}

main(){
    int arr[] = {2, 3, 5, 2, 10};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Before Sorting: ";
    PrintArray(arr, size);

    HeapSort(arr, size);

    cout << "\nAfter Sorting: ";
    PrintArray(arr, size);
}




















