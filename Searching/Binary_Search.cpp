// Using Iteration Process

/*#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int l, int r, int x){
    while (l <= r){
        int mid = l + (r-l)/2;

        if (arr[mid] == x){
            return mid;
        }

        if (arr[mid] > x){
            r = mid-1;
        }
        else {
            l = mid+1;
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


// Using Recursive Approach

#include <bits/stdc++.h>
using namespace std;

int BinarySearch (int arr[], int l, int r, int x){
    while (l <= r){
        int mid = l+(r-l)/2;

        if (arr[mid] == x){
            return mid;
        }

        if (arr[mid] < x){
            return BinarySearch (arr, mid+1, r, x);
        }
        else{
            return BinarySearch (arr, l, mid-1, x);
        }
    }

    return -1;
}

int Lower_Bound(int arr[], int l, int r, int x){
    while(l <= r){
        int mid = l+(r-l)/2;
        if(arr[mid] < x){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }

    if(arr[l] >= x){
        return l;
    }
    if(arr[r] >= x){
        return r;
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

    int lb = Lower_Bound(arr, left, right, key);
    cout << "Lower Bound: " << lb << endl;

}


















