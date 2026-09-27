#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<int> dp(n, 1); // cada elemento solo ya es una subsecuencia válida de longitud 1

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (p[j] < p[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int respuesta = 0;
    for (int i = 0; i < n; i++) respuesta = max(respuesta, dp[i]);

    cout << respuesta << endl;
}