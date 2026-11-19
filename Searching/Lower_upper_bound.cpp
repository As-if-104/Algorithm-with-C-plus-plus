#include <bits/stdc++.h>
using namespace std;

int Lower_Bound(int arr[], int l, int r, int x)
{
    while (r-l > 1)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    if (arr[l] >= x)
    {
        return l;
    }
    if (arr[r] >= x)
    {
        return r;
    }
    return -1;
}

int Upper_Bound(int arr[], int low, int high, int x){
    while(high - low > 1){
        int mid = low + (high - low) / 2;
        if(arr[mid] <= x){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }

    if(arr[low] > x){
        return low;
    }
    if(arr[high] > x){
        return high;
    }

    return-1;
}
main()
{
    int arr[] = {-134, 23, 34, 100, 13450};
    int length = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the element: ";
    cin >> key;
    int left = 0;
    int right = length - 1;

    int lb = Lower_Bound(arr, left, right, key);
    cout << "Lower Bound: " << lb << endl;

    int ub = Upper_Bound(arr, left, right, key);
    cout << "Upper Bound: " << ub << endl;
}
