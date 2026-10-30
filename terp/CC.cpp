#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

vector<vector<int>> adj;
vector<int> comp;                     // comp[v] = número de componente, 0 = no visitado

void dfs(int v, int c) {
    comp[v] = c;
    for (int w : adj[v])
        if (comp[w] == 0) dfs(w, c);
}

int main() {
    FIN;
    int n, m;
    cin >> n >> m;
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    comp.assign(n, 0);
    int numCC = 0;
    for (int v = 0; v < n; v++)
        if (comp[v] == 0) dfs(v, ++numCC);

    cout << numCC << '\n';
}