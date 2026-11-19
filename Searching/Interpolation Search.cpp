// Using Recursive Approach

#include <bits/stdc++.h>
using namespace std;

int InterpolationSearch (int arr[], int left, int right, int key){
    int Estimated_Index;

    if (left <= right && arr[left] <= key && arr[right] >= key){
        Estimated_Index = left + (((double)(right-left) / (arr[right]-arr[left])) * (key - arr[left]));

        if (arr[Estimated_Index] == key){
            return Estimated_Index;
        }

        if (arr[Estimated_Index] > key){
            return InterpolationSearch (arr, left, Estimated_Index-1, key);
        }

        if (arr[Estimated_Index] < key){
            return InterpolationSearch (arr, Estimated_Index+1, right, key);
        }
    }

    return -1;
}

main(){
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int x;
    cout << "Enter the element: ";
    cin >> x;
    int length = sizeof(arr) / sizeof(arr[0]);

    int index = InterpolationSearch (arr, 0, length-1, x);

    if (index != -1){
        cout << "Key " << x << " is present at index: " << index << " And at position: " << index+1;
    }
    else{
        cout << "Key " << x << " is not present here!";
    }
}
