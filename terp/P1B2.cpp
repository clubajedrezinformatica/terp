#include <bits/stdc++.h>

using namespace std; 

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

int main(){
    FIN; 
    const int MAXV = 100000;
    int n; 
    cin >> n;
    vector <long long> w(MAXV + 1, 0);
    for(int i = 0; i < n; i++){
        int x; 
        cin >> x; 
        w[x]+= x; 
    }
    vector<long long> dp(MAXV+1, 0);
    dp[0] = 0; 
    dp[1] = w[1];
    for(int v = 2; v <= MAXV; v++){
        dp[v] = max(dp[v-1], w[v]+dp[v-2]);
    }
    cout << dp[MAXV] << "\n";
    return 0;
}
