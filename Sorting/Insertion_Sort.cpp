#include <bits/stdc++.h>
using namespace std;

void InsertionSort (int arr[], int len){
    for (int i = 1 ; i < len; i++){
        int temp = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void PrintArray (int arr[], int len){
    for (int i = 0; i < len; i++){
        cout << " " << arr[i];
    }
}

main(){
    int arr[] = {0, 5, 1, 6, -1};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    PrintArray(arr, len);

    InsertionSort (arr, len);

    cout << "\nAfter Sorting: ";
    PrintArray(arr, len);
}
