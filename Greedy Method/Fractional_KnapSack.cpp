#include <bits/stdc++.h>
using namespace std;

typedef struct item{
    int weight, profit;

    item(int profit, int weight){
        this->weight = weight;
        this->profit = profit;
    }
} item;

static bool cmp(item a, item b){
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

double fractional_KnapSack (item arr[], int w, int n){
    sort(arr, arr + n, cmp);
    double max_profit = 0.0;

    for(int i = 0; i < n; i++){
        if(arr[i].weight < w){
            w -= arr[i].weight;
            max_profit += arr[i].profit;
        }

        else{
            max_profit += arr[i].profit * ((double)w / (double)arr[i].weight);
            break;
        }
    }

    return max_profit;
}

main(){
    int w = 50;
    item arr[] = {{60, 10}, 
                  {100, 20},
                  {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum profit: " << fractional_KnapSack(arr, w, n) << endl;
    return 0;
}