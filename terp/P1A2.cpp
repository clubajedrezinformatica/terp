#include <bits/stdc++.h>
using namespace std; 

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0) 
const long long MOD = 1e9 + 7; 

int main() {
    int n; 
    cin >> n;

    vector<long long> dp(n+1, 0);
    dp[0] = 1;

    for (int s = 1; s <= n; s++){
        for(int d = 1; d <= 6; d++){
            if(s - d >= 0) {
                dp[s] = (dp[s] + dp[s-d]) % MOD;
            }
        }
    }
    cout << dp[n] << "\n";
}