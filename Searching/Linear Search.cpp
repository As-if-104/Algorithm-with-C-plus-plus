#include <bits/stdc++.h>
using namespace std;

int LinearSearch (int arr[], int L, int x){
    for (int i = 0; i < L; i++){
        if (arr[i] == x){
            return i;
        }
    }
    return -1;
}
main(){
    int arr[] = {2, 1, 3, 10, 5, 8, 7};
    int x;
    cout << "Enter a number: ";
    cin >> x;
    int length = sizeof(arr) / sizeof(arr[0]);

    int result = LinearSearch(arr, length, x);

    if (result == -1){
        cout << "Element " << x << " is not present here!";
    }
    else{
        cout << "Element is present at index: " << result << " And at position: " << result+1;
    }
}
