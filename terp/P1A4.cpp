#include <bits/stdc++.h>
using namespace std; 

const long long MOD = 1e9 + 7; 

int main(){
    int n, x; 
    cin >> n >> x; 

    vector <int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    vector <long long> dp(x+1, 0);
    dp[0] = 1; 

    for (int s = 1; s <= x; s++) {
        long long suma = 0;
        for (int i = 0; i < n; i++) {
            if (s - coins[i] >= 0) {
                suma += dp[s - coins[i]];
            }
        }
        dp[s] = suma % MOD;
    }
    cout << dp[x] << endl;
}