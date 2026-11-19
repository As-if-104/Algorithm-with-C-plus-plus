#include <bits/stdc++.h>
using namespace std;

int minCoinsRequired(vector<int> &Coin, vector<vector<int>> &memo, int idx, int amount){
    if (amount == 0)
        return 0;
    if (amount < 0 || idx == Coin.size())
        return INT_MAX;

    if (memo[idx][amount] != -1)
        return memo[idx][amount];

    int take = INT_MAX;

    if (Coin[idx] > 0)
    {
        take = minCoinsRequired(Coin, memo, idx, amount - Coin[idx]);
        if (take != INT_MAX)
            take++;
    }

    int noTake = minCoinsRequired(Coin, memo, idx, amount - Coin[idx]);

    return memo[idx][amount] = min(take, noTake);
}
int minCoins(vector<int> &Coin, int amount){
    vector<vector<int>> memo(Coin.size(), vector<int>(amount+1, -1));
    int ans = minCoinsRequired(Coin, memo, 0, amount); 
    return ans!=INT_MAX ? ans : -1;
}
main(){
    vector<int> Coin = {9, 6, 5, 3};
    int amount = 11;
    
    cout << minCoins(Coin, amount) << endl;
    
}