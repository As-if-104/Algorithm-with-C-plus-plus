#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int low, int mid, int high);

void MergeSort (int arr[], int low, int high){
    if (low < high){
        int mid = (low+high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}

void Merge(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int *B = new int[high-low+1];

    while (i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            B[k-low] = arr[i];
            i++;
        }
        else{
            B[k-low] = arr[j];
            j++;
        }
        k++;
    }

    if(i > mid){
        while (j <= high){
            B[k-low] = arr[j];
            j++;
            k++;
        }
    }
    else{
        while (i <= mid){
            B[k-low] = arr[i];
            i++;
            k++;
        }
    }

    for (k = low; k <= high; k++){
        arr[k] = B[k-low];
    }

    delete [] B;
}

void PrintArray (int arr[], int len){
    for (int i = 0; i < len; i++){
        cout << " " << arr[i];
    }
}

main(){
    int arr[] = {0, 5, 1, 6, -1, -1, 89};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    PrintArray(arr, len);

    MergeSort (arr, 0, len-1);

    cout << "\nAfter Sorting: ";
    PrintArray(arr, len);
}

