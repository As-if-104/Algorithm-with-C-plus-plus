#include <bits/stdc++.h>
using namespace std;

int BinarySearch (int arr[], int, int, int);

int ExponentialSearch (int arr[], int length, int key){
    if (arr[0] == key){
        return 0;
    }

    int i = 1;
    while (i < length && arr[i] <= key){
        i *= 2;
    }

    return BinarySearch (arr, i/2, min(i, length-1), key);
}

int BinarySearch (int arr[], int left, int right, int key){
    if (left <= right){
        int mid = left + (right-left)/2;

        if (arr[mid] == key){
            return mid;
        }

        if (arr[mid] > key){
            return BinarySearch (arr, left, mid-1, key);
        }
        else{
            return BinarySearch (arr, mid+1, right, key);
        }
    }

    return -1;
}

main(){
    int arr[] = {10, 20, 30, 40, 50};
    int x;
    cout << "Enter the key: ";
    cin >> x;
    int len = sizeof(arr) / sizeof(arr[0]);

    int index = ExponentialSearch (arr, len, x);

    if (index != -1){
        cout << "Key " << x << " is present at index: " << index << " And at position: " << index+1;
    }
    else{
        cout << "Key " << x << " is not present here!";
    }
}








