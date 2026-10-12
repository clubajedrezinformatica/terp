#include <bits/stdc++.h>
using namespace std; 
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
const long long MOD = 1000000007;
int main(){
    FIN; 
    int n, k, d;
    cin >> n >> k >> d;
    vector<array<long long, 2>> dp(n+1, {0, 0});
    dp[0][0] = 1; 
    dp[0][1] = 0;
    for(int s=1; s <= n; s++){
        for(int j=1; j <= min(k, s); j++){
            if(j<d){
                dp[s][0] = (dp[s][0] + dp[s-j][0]) % MOD; 
                dp[s][1] = (dp[s][1] + dp[s-j][1]) % MOD; 
            }else{
                dp[s][1] = (dp[s][1] + dp[s-j][0] + dp[s-j][1])% MOD;
            }
        }
    }
    cout << dp[n][1] << "\n";
}