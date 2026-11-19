#include <bits/stdc++.h>
using namespace std;

void SentinelLinearSearch(int arr[], int Len, int key){
    int last = arr[Len-1];

    arr[Len-1] = key;
    int i = 0;

    while (arr[i] != key){
        i++;
    }

    arr[Len-1] = last;

    if ((i < Len-1) || (arr[i] == key)){
        cout << "Key: " << key << " is present at index: " << i << " And at position: " << i+1;
    }
    else{
        cout << "Key " << key << " is not present here!";
    }
}

main(){
    int arr[] = {100, 20, 60, 64, -132};
    int length = sizeof(arr) / sizeof(arr[0]);
    int x;
    cout << "Enter the number: ";
    cin >> x;

    SentinelLinearSearch (arr, length, x);
}
