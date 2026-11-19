#include <bits/stdc++.h>
using namespace std;

void CountingSort (int arr[], int len, int pos);

void RadixSort (int arr[], int len){
    int Max = 0;
    for (int i = 0; i < len; i++){
        Max = max(arr[i], Max);
    }

    for (int pos = 1; Max/pos > 0; pos *= 10){
        CountingSort (arr, len, pos);
    }
}

void CountingSort (int arr[], int len, int pos){
    int Count[10] = {0};
    int B[len];

    for (int i = 0; i < len; i++){
        ++Count[(arr[i]/pos)%10];
    }
    for (int i = 1; i < 10; i++){
        Count[i] = Count[i] + Count[i-1];
    }
    for (int i = len-1; i >= 0; i--){
        B[--Count[(arr[i]/pos)%10]] = arr[i];
    }
    for (int i = 0; i < len; i++){
        arr[i] = B[i];
    }
}

PrintArray (int arr[], int len){
    for (int i = 0; i < len; i++){
        cout << " " << arr[i];
    }
}
main(){
    int arr[] = {1, 345, 1095, 32, 15678};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Before Sorting: ";
    PrintArray(arr, size);

    RadixSort(arr, size);

    cout << "\nAfter Sorting: ";
    PrintArray(arr, size);
}












