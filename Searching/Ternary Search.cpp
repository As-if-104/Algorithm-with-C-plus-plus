// Using Iteration Process

#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int l, int r, int x){
    while (l <= r){
        int mid1 = l + (r-l)/2;
        int mid2 = r - (r-l)/2;

        if (arr[mid1] == x){
            return mid1;
        }
        if (arr[mid2] == x){
            return mid2;
        }

        if (arr[mid1] > x){
            r = mid1-1;
        }
        else if (arr[mid2] < x) {
            l = mid2+1;
        }
        else{
            l = mid1+1;
            r = mid2-1;
        }
    }

    return -1;
}

main(){
    int arr[] = {-134, 23, 34, 100, 13450};
    int length = sizeof(arr)/sizeof(arr[0]);
    int key;
    cout << "Enter the element: ";
    cin >> key;
    int left = 0;
    int right = length-1;

    int result = BinarySearch(arr, left, right, key);

    if (result != -1){
        cout << "Key: " << key << " is present at index: " << result << " And at position: " << result+1;
    }
    else{
        cout << "Key " << key << " is not present here!";
    }
}


// Using Recursive Approach

/*#include <bits/stdc++.h>
using namespace std;

int BinarySearch (int arr[], int l, int r, int x){
    while (l <= r){
        int mid1 = l+(r-l)/2;
        int mid2 = r-(r-l)/2;

        if (arr[mid1] == x){
            return mid1;
        }

        if (arr[mid2] == x){
            return mid2;
        }

        if (arr[mid1] > x){
            return BinarySearch (arr, l, mid1-1, x);
        }
        else if (arr[mid2] < x){
            return BinarySearch (arr, mid2+1, r, x);
        }
        else{
            return BinarySearch (arr, mid1+1, mid2-1, x);
        }
    }

    return -1;
}

main(){
    int arr[] = {-134, 23, 34, 100, 13450};
    int length = sizeof(arr)/sizeof(arr[0]);
    int key;
    cout << "Enter the element: ";
    cin >> key;
    int left = 0;
    int right = length-1;

    int result = BinarySearch(arr, left, right, key);

    if (result != -1){
        cout << "Key: " << key << " is present at index: " << result << " And at position: " << result+1;
    }
    else{
        cout << "Key " << key << " is not present here!";
    }
}*/


















