#include <bits/stdc++.h>

using namespace std;

#define FIN ios::sync_with_stdio(false); cin.tie(nullptr)

int main() {
    FIN;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string palabra;
        cin >> palabra;

        if (palabra.length() > 10) {
            cout << palabra.front()
                 << palabra.length() - 2
                 << palabra.back()
                 << '\n';
        } else {
            cout << palabra << '\n';
        }
    }

    return 0;
}