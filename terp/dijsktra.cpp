#include <bits/stdc++.h>

using namespace std; 

typedef long long ll; 
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
const ll INF = 1e18+7; 

struct Arista {
    int from, to, w; 
    Arista() {}
    Arista(int _from, int _to, int _w){
        from = _from; to = _to; w = _w;
    }
}; 

struct Nodo{
    int id; ll dist; 
    Nodo() {}
    Nodo(int _id, ll _dist){
        id = _id, dist = _dist; 
    }
    bool operator < (Nodo aux) const{
        return dist > aux.dist; 
    }
}; 

vector<ll> dijkstra(int start, vector<vector<Arista>> &g, int n){
    vector<ll> dist(n+1, INF);
    priority_queue <Nodo> pq; 
    pq.push(Nodo(start, 0));
    while(pq.size() > 0){
        auto[cur,d] = pq.top();
        pq.pop();
        if(dist[cur] != INF) continue; 
        dist[cur] = d; 
        for(Arista a : g[cur]){
            if(dist[a.to] == INF){
                pq.push(Nodo(a.to, d+a.w));
            }
        }
    }
    return dist; 
}
int main(){
    FIN; 

    int n, m; 
    cin >> n >> m; 
    vector<vector<Arista>> g(n+1);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w; 
        g[u].push_back(Arista(u, v, w));
    }
    vector<ll> dist = dijkstra(1, g, n);
    for(int i=1; i<=n; i++){
        if(dist[i] == INF) cout << -1 << " "; 
        else cout << dist[i] << " "; 
    }
    cout << "\n";
    return 0;
}