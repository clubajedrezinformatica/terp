#include <bits/stdc++.h> 
using namespace std; 
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
const long long MENOS_INF = LLONG_MIN /2; 

int main(){
    FIN; 
    int n; 
    cin >> n; 
    vector<int> fila_uno(n+1), fila_dos(n+1); 
    for(int i=1; i<=n; i++) cin >> fila_uno[i];
    for(int j=1; j<=n; j++) cin >> fila_dos[j];

    vector<vector<long long>> dp(n+1, vector<long long>(3));
    //declaración de casos base 
    dp[0][0] = 0; //si no se elige, no suma 
    dp[0][1] = MENOS_INF; //permite iniciar recurrencia  
    dp[0][2] = MENOS_INF; //permite iniciar recurrencia 
    //loop principal 
    for(int i=1; i<=n; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + fila_uno[i]; 
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + fila_dos[i];
    } 
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
}