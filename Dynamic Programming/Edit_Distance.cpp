// Using Recursion

// #include <bits/stdc++.h>
// using namespace std;

// int Edit_Distance(string &s1, string &s2, int m, int n){
//     if(m == 0) return n;
//     if(n == 0) return m;

//     if(s1[m-1] == s2[n-1]) return Edit_Distance(s1, s2, m-1, n-1);

//     return 1 + min({Edit_Distance(s1, s2, m-1, n-1),
//                     Edit_Distance(s1, s2, m, n-1),
//                     Edit_Distance(s1, s2, m-1, n)});
// }
// main(){
//     string s1 = "Asiiiiiiiif";
//     string s2 = "Rodela";
//     int m = s1.length();
//     int n = s2.length();

//     cout << "Result: " << Edit_Distance(s1, s2, m, n) << endl;
// }


// Using Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

int Edit_Distance(string &s1, string &s2, int m, int n){
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for(int i = 0; i <= m; i++){
        dp[i][0] = i;
    }

    for(int j = 0; j <= n; j++){
        dp[0][j] = j;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
            }
        }
    }

    return dp[m][n];
}

main(){
    string s1 = "Asiiiiiiiif";
    string s2 = "Rodela";
    int m = s1.length();
    int n = s2.length();
    
    cout << "Result: " << Edit_Distance(s1, s2, m, n) << endl;
}