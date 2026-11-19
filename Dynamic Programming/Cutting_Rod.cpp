// Using Recursion

// #include <bits/stdc++.h>
// using namespace std;

// int CutRod(int i, vector<int> &price){
//     if(i <= 0)
//         return 0;
//     int ans = 0;

//     for(int j = 1; j <= i; j++){
//         ans = max(ans, price[j-1] + CutRod(i-j, price));
//     }

//     return ans;
// }
// main(){
//     vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
//     int n = price.size();
//     cout << CutRod(n, price);
// }


// Using Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

int CutRod(int i, vector<int> &price, vector<int> &dp){
    if(i <= 0)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int ans = 0;

    for(int j = 1; j <= i; j++){
        ans = max(ans, price[j-1] + CutRod(i-j, price, dp));
    }

    dp[i] = ans;
    return ans;
}

main(){
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    vector<int> dp(n+1, -1);
    cout << CutRod(n, price, dp);
}