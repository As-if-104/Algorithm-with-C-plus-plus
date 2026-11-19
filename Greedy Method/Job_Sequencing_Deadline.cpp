#include <bits/stdc++.h>
using namespace std;

typedef struct job{
    char id;
    int deadline;
    int profit;

} job;

bool compare (job a, job b){
    return (a.profit > b.profit);
}

void Job_Sequencing(job arr[], int n){
    sort(arr, arr+n, compare);
    int result[n];
    int slot[n];

    for(int i = 0; i < n; i++){
        slot[i] = 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = min(n, arr[i].deadline)-1; j >= 0; j--){
            if(slot[j] == 0){
                slot[j] = 1;
                result[j] = i;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << "Job " << arr[result[i]].id << " is scheduled at slot " << i << endl;
    }

    for(int i = 0; i < n; i++){
        if(slot[i]){
            cout << arr[result[i]].id << " ";
        }
    }
}

main(){
    job arr[] = { {'a', 4, 20}, 
                  {'b', 1, 10}, 
                  {'c', 3, 40}, 
                  {'d', 2, 30} };

    int n = sizeof(arr)/sizeof(arr[0]);
    Job_Sequencing(arr, n);
    return 0;
}