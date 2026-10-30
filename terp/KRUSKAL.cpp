#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

vector<int> p, rnk;

int findSet(int x) {
    if (x != p[x]) p[x] = findSet(p[x]);
    return p[x];
}

void unionSet(int x, int y) {
    int r = findSet(x), s = findSet(y);
    if (r == s) return;
    if (rnk[r] < rnk[s]) swap(r, s);
    p[s] = r;
    if (rnk[r] == rnk[s]) rnk[r]++;
}

int main() {
    FIN;
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> aristas(m);         // (peso, u, v): el peso primero para ordenar
    for (auto& [w, u, v] : aristas) cin >> u >> v >> w;
    sort(aristas.begin(), aristas.end());          // orden no decreciente de peso

    p.resize(n); rnk.assign(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;

    long long costo = 0;
    int usadas = 0;
    for (auto [w, u, v] : aristas) {
        if (findSet(u) != findSet(v)) {            // no forma ciclo
            costo += w;
            unionSet(u, v);
            usadas++;
        }
    }

    if (usadas != n - 1) cout << "no es conexo\n";
    else cout << costo << '\n';
}