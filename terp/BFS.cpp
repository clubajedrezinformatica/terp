#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

int main() {
    FIN;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);          // no dirigido: la arista va en las dos listas
    }
    int s;
    cin >> s;

    vector<int> dist(n, n);           // n hace de infinito: ninguna distancia llega a n
    queue<int> cola;
    dist[s] = 0;
    cola.push(s);
    while (!cola.empty()) {
        int t = cola.front(); cola.pop();
        for (int w : adj[t]) {
            if (dist[w] == n) {       // no visitado
                dist[w] = dist[t] + 1;
                cola.push(w);
            }
        }
    }

    for (int v = 0; v < n; v++) cout << dist[v] << ' ';
    cout << '\n';
}