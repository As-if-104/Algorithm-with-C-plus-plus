// The Kadane's Algorithm

#include <bits/stdc++.h>
using namespace std;

int Max_SubArray_Sum(vector<int> &arr){
    int res = arr[0];
    int maxEnding = arr[0];

    for(int i = 0; i < arr.size(); i++){
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum SubArray sum: " << Max_SubArray_Sum(arr) << endl;
}

// Using Divide and Conqure Approach

#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a > b)? a : b;
}

int max(int a, int b, int c){
    return max(max(a, b), c);
}
int max_crossing_sum(int arr[], int l, int m, int h){
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i = m; i >= l; i--){
        sum += arr[i];
        if(left_sum < sum){
            left_sum = sum;
        }
    }

    int right_sum = INT_MIN;
    for(int i = m + 1; i <= h; i++){
        sum += arr[i];
        if(right_sum < sum){
            right_sum = sum;
        }
    }

    return max(left_sum, right_sum, left_sum + right_sum - arr[m]);
}
int max_SubArray_Sum(int arr[], int l, int h){
    if(l > h){
        return INT_MIN;
    }
    if(l == h){
        return arr[l];
    }

    int mid = (l + h) / 2;

    int left_sum = max_SubArray_Sum(arr, l, mid-1);
    int right_sum = max_SubArray_Sum(arr, mid + 1, h);
    int cross_sum = max_crossing_sum(arr, l, mid, h);

    return max(left_sum, right_sum, cross_sum);
}

main(){
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum Subarray sum: " << max_SubArray_Sum(arr, 0, size-1) << endl;
}



// #include <bits/stdc++.h>
// using namespace std;

// struct SubArrayInfo
// {
//     int sum;
//     int start;
//     int end;
// };

// SubArrayInfo Max_SubArray_Sum(vector<int> &arr)
// {
//     SubArrayInfo result;
//     result.sum = arr[0];
//     int maxEnding = arr[0];

    
//     result.start = 0;
//     result.end = 0;
//     int start_temp = 0;

//     for (int i = 1; i < arr.size(); i++)
//     {
        
//         if (arr[i] > maxEnding + arr[i])
//         {
//             maxEnding = arr[i];
//             start_temp = i;
//         }
//         else
//         {
//             maxEnding = maxEnding + arr[i];
//         }

        
//         if (maxEnding > result.sum)
//         {
//             result.sum = maxEnding;
//             result.start = start_temp;
//             result.end = i;
//         }
//     }

//     return result;
// }

// int main()
// {
//     vector<int> arr = {2, -4, 1, 9, -6, 7, 3};
//     SubArrayInfo result = Max_SubArray_Sum(arr);

//     cout << "Maximum SubArray sum: " << result.sum << endl;
//     cout << "SubArray elements: ";
//     for (int i = result.start; i <= result.end; i++)
//     {
//         cout << arr[i];
//         if (i != result.end)
//             cout << ", ";
//     }
//     cout << endl;
//     cout << "Start index: " << result.start << endl;
//     cout << "End index: " << result.end << endl;

//     return 0;
// }