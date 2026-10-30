#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

vector<vector<int>> adj;
vector<int> dfnum, low, padre;
vector<bool> esPA;
vector<pair<int,int>> puentes;
int contador = 1, dfsRoot, hijosRoot;

void buscarPA(int v) {
    dfnum[v] = low[v] = contador++;
    for (int w : adj[v]) {
        if (dfnum[w] == 0) {                       // w no visitado: arista del árbol
            padre[w] = v;
            if (v == dfsRoot) hijosRoot++;
            buscarPA(w);
            if (low[w] >= dfnum[v] && v != dfsRoot) esPA[v] = true;
            if (low[w] > dfnum[v]) puentes.push_back({v, w});
            low[v] = min(low[v], low[w]);
        } else if (w != padre[v]) {                // arista hacia atrás
            low[v] = min(low[v], dfnum[w]);
        }
    }
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

    dfnum.assign(n, 0); low.assign(n, 0); padre.assign(n, -1); esPA.assign(n, false);
    for (int v = 0; v < n; v++) {
        if (dfnum[v] == 0) {
            dfsRoot = v; hijosRoot = 0;
            buscarPA(v);
            esPA[v] = (hijosRoot > 1);             // la raíz es PA si tiene 2 o más hijos
        }
    }

    for (int v = 0; v < n; v++) if (esPA[v]) cout << v << ' ';
    cout << '\n';
    for (auto [u, v] : puentes) cout << u << '-' << v << ' ';
    cout << '\n';
}