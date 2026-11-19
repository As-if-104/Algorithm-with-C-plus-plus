#include <bits/stdc++.h>
using namespace std;

void ShellSort (int arr[], int len){
    for (int gap = len/2; gap >= 1; gap /= 2){
        for (int j = gap; j < len; j++){
            for (int i = j-gap; i >= 0; i -= gap){
                if (arr[i+gap] > arr[i]){
                    break;
                }
                else{
                    swap (arr[i+gap], arr[i]);
                }
            }
        }
    }
}

PrintArray (int arr[], int len){
    for (int i = 0; i < len; i++){
        cout << " " << arr[i];
    }
}

main(){
    int arr[] = {12, 23, 5, 1, 6, 8, 23, 45, -1, 0, 2, -4, -3, 06, -98};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    PrintArray(arr, size);

    ShellSort (arr, size);

    cout << "\nAfter Sorting: ";
    PrintArray (arr, size);
}
