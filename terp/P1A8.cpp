#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> p(n), v(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = x; w >= p[i]; w--) {
            dp[w] = max(dp[w], dp[w - p[i]] + v[i]);
        }
    }

    cout << dp[x] << endl;
}