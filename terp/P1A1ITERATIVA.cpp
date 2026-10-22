#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)

using namespace std; 

const long long MOD = 1e9+7;

int main(){
    FIN;
    int k; 
    cin >> k;
    vector<long long> dp(5, 1); 
    for(int i = 2; i <= k; i++){
        vector<long long>  nuevo(5);
        nuevo[0] = dp[1];
        nuevo[1] = (dp[0] + dp[2]) % MOD; 
        nuevo[2] = (dp[1] + dp[3]) % MOD; 
        nuevo[3] = (dp[2] + dp[4]) % MOD; 
        nuevo[4] = (dp[3]);
        dp = nuevo;
    }
    long long respuesta = 0; 
    for(long long v : dp) respuesta = (respuesta + v) % MOD; 
    cout << respuesta << "\n";
}