#include <bits/stdc++.h>
using namespace std;

long long int Power(long long int x, long long int n){
    long long int temp;
    if(n == 0){
        return 1;
    }
    if(n%2 == 0){
        temp = Power(x, n/2);
        return temp*temp;
    }
    else{
        temp = Power(x, n/2);
        return x*temp*temp;
    }
}
main(){
    long long int x, n;
    cout << "Enter x and n: ";
    cin >> x >> n;
    long long int res = Power(x, n);
    cout << "Result: " << res << endl;
}