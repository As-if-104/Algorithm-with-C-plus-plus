#include <bits/stdc++.h>
using namespace std;

int PartitionMethod(int arr[], int low, int high)
{
    int start = low;
    int end = high;
    int pivot = arr[low];
    int random = rand();

    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[low], arr[end]);
    return end;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int idx = PartitionMethod(arr, low, high);
        QuickSort(arr, low, idx - 1);
        QuickSort(arr, idx + 1, high);
    }
}

void PrintArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << " " << arr[i];
    }
}

main()
{
    int arr[] = {9, 7, 5, 3, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    PrintArray(arr, len);

    QuickSort(arr, 0, len - 1);

    cout << "\nAfter Sorting: ";
    PrintArray(arr, len);
}
