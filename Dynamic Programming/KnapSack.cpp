// Using Recursion

// #include <bits/stdc++.h>
// using namespace std;

// int KnapSack(vector<int> &wt, vector<int> &P, int i, int W){
//     if(i == 0 || W == 0) return 0;

//     if(wt[i-1] > W){
//         return KnapSack(wt, P, i-1, W);
//     }

//     return max(KnapSack(wt, P, i-1, W), P[i-1] + KnapSack(wt, P, i-1, W-wt[i-1]));
// }
// main(){
//     vector<int> profit = {60, 100, 120};
//     vector<int> weight = {10, 20, 30};
//     int W = 50;  
//     int n = weight.size();

//     cout << "Maximum profit: " << KnapSack(weight, profit, n, W) << endl;
//     return 0;
// }




// Using Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

int KnapSack(vector<int> &wt, vector<int> &P, int W){
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1));

    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0){
                dp[i][w] = 0;            }
            else if(w >= wt[i-1])
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i-1]]+P[i-1]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}
main(){
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;  

    cout << "profit: " << KnapSack(weight, profit, W) << endl;
}