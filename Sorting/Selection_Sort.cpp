#include <bits/stdc++.h>
using namespace std;

void SelectionSort (int arr[], int len){
    for (int i = 0; i < len-1; i++){
        int min_idx = i;
        for (int j = i+1; j < len; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }

        if (min_idx != i){
            swap(arr[min_idx], arr[i]);
        }
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

    SelectionSort (arr, len);

    cout << "\nAfter Sorting: ";
    PrintArray(arr, len);
}
