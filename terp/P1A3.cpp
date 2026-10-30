#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std; 
const int INF = 1e9;

int main(){
    FIN; 
    int n, x;
    cin >> n >> x; 

    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    vector<int> dp(x + 1, INF);
    dp[0] = 0; 

    for(int s = 0; s<=x; s++){
        for (int i = 0; i<n; i++){
            if(s - coins[i] >= 0){
                dp[s] = min(dp[s], dp[s - coins[i]] + 1);
            }
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]) << "\n"; 
}