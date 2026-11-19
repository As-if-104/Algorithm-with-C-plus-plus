#include <bits/stdc++.h>
using namespace std;

void CountingSort (int arr[], int len){
    int Max = 0;
    for (int i = 0; i < len; i++){
        Max = max(Max, arr[i]);
    }

    int count[Max+1] = {0};
    int B[len];

    for (int i = 0; i < len; i++){
        ++count[arr[i]];
    }
    for (int i = 1; i <= Max; i++){
        count[i] = count[i] + count[i-1];
    }
    for (int i = len-1; i >= 0; i--){
        B[--count[arr[i]]] = arr[i];
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
    int arr[] = {9, 9, 5, 1, 20123, 2, 2, 1, 0, 0, 3, 4, 409};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    PrintArray(arr, size);

    CountingSort (arr, size);

    cout << "\nAfter Sorting: ";
    PrintArray(arr, size);
}
