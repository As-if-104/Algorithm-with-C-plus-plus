#include <bits/stdc++.h>
using namespace std;

/*int JumpSearch(int arr[], int length, int key){
    int start = 0;
    int end = sqrt(length);

    while (arr[end] < key){
        start = end;
        end = end + sqrt(length);
        if (end > length-1){
            end = length-1;
            //cout << end << endl;
        }
    }
    for (int i = start; i < end; i++){
        if (arr[i] == key){
            return i;
        }
    }

    return -1;
}*/

int JumpSearch (int arr[], int len, int key){
    int low;
    int jump = sqrt(len);

    for (int i = 0; i < len; i+= jump){
        if (arr[i] == key){
            return i;
        }
        if (arr[i] < key){
            low = i;
        }
        if (arr[i] > key){
            break;
        }
    }

    for (int i = low; i < len; i++){
        if (arr[i] == key){
            return i;
        }
    }

    return -1;
}

main(){
    int arr[] = {10, 20, 30, 40, 100, 200, 300};
    int len = sizeof(arr)/sizeof(arr[0]);
    int x;
    cout << "Enter the Key Element: ";
    cin >> x;

    int index = JumpSearch (arr, len, x);
    if (index != -1){
        cout << "key " << x << " is present at index: " << index << " And at position: " << index+1;
    }
    else{
        cout << "Key: " << x << " is not present here!";
    }
}
