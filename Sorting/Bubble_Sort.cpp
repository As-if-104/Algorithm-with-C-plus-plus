#include <bits/stdc++.h>
using namespace std;

void BubbleSort (int arr[], int len){
    int i, j;
    bool swapped;
    int count = 0;

    for (i = 0; i < len-1; i++){
        swapped = false;
        for (j = 0; j < len-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
                count++;
            }
        }

        if (swapped == false){
            break;
        }
    }

    cout << count;
}

void PrintArray (int arr[], int len){
    for (int i = 0; i < len; i++){
        cout << " " << arr[i];
    }
}

main(){
    int arr[] = {1, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    PrintArray(arr, len);

    BubbleSort (arr, len);

    cout << "\nAfter Sorting: ";
    PrintArray(arr, len);
}










































