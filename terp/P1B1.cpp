#include <bits/stdc++.h>

using namespace std; 

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

int main(){ 
    FIN; 
    int t; 
    cin >> t; 
    while(t--){
        int n; 
        cin >> n; 
        vector<int> a(2*n+1); //a[1..2n]; a[0] sin usar 
        vector<int> primera(n+1, 0); //se indexa por valor 1..n; 0 = no apareció
        vector <long long> dp(2*n+1, 0); // dp[0] = 0 (caso base)
        for(int i = 1; i <= 2*n; i++){
            cin >> a[i];
            int v = a[i];
            if(primera[v] == 0){
                primera[v] = i;
                dp[i] = 1 + dp[i-1];
            }else{
                long long largo = i - primera[v] + 1; 
                long long A = 1 + dp[i-1];
                long long B = largo * largo + dp[primera[v] - 1];
                dp[i] = max(A, B);
            }
        }
        cout << dp[2*n] << " \n";
    }

    return 0; 
}