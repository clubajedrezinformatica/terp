#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> enteros(n);
    for (int i = 0; i < n; i++) cin >> enteros[i];

    vector<int> dp(n, 1); // cada elemento solo ya es una subsecuencia válida de longitud 1

    for (int i = 0; i < n; i++) {//todo el arreglo enteros de 0 a n 
        for (int j = 0; j < i; j++) {//
            if (enteros[i] % enteros[j] == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int respuesta = 0;
    for (int i = 0; i < n; i++) respuesta = max(respuesta, dp[i]);

    cout << respuesta << endl;
}