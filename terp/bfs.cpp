#include <bits/stdc++.h> 

using namespace std; 

typedef long long ll; 
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)

vector<int> bfs(int start, vector<vector<int>> &g, int n){
    vector<int> dist(n+1,n);
    queue<int> cola; 
    dist[start] = 0; 
    cola.push(start);
    while(!cola.empty()){
        int t = cola.front();
        cola.pop();
        for(int next : g[t]){
            if(dist[next] == n){
                dist[next] = dist[t] + 1;
                cola.push(next);
            }
        }
    }
    return dist; 
}

int main(){
    FIN; 

    int n, m; 
    cin >> n >> m; 
    vector <vector<int>> g(n+1);
    for(int i=0; i<m; i++){
        int u, v; 
        cin >> u >> v; 
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dist = bfs(1,g,n);
    for(int i=1; i<=n; i++){
        if(dist[i] == n) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << "\n";
    return 0;
}