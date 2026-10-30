#include <bits/stdc++.h>
using namespace std; 
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
const int INF = 1e9+7; 
int tiempo = 0; 

void DFS(int cur, int p, vector<int>& tEnt, vector <int>& anc, vector<pair<int,int>>& puentes, vector<vector<int>>& g){
    tEnt[cur] = tiempo; 
    anc[cur] = tiempo; 
    tiempo++; 
    for(int next : g[cur]){
        if(next == p) continue; 
        if(tEnt[next] == -1){
            DFS(next, cur, tEnt, anc, puentes, g);
            if(anc[next] > tEnt[cur]){
                puentes.push_back({cur+1, next+1});
            }
            anc[cur] = min(anc[cur], anc[next]);
        }else{
            anc[cur] = min(anc[cur],tEnt[next]);
        }
    }
}

int main() {
    FIN; 
    int n, m; 
    cin >> n >> m; 
    vector<vector<int>> g(n); 
    for(int i=0; i<m; i++){
        int u, v; 
        cin >> u >> v; 
        u--; v--; 
        g[u].push_back(v); 
        g[v].push_back(u);
    }

    vector<int> tEnt(n, -1), anc(n, INF); 
    vector<pair<int,int>> puentes; 

    for(int i=0; i<n; i++){
        if(tEnt[i]==-1){
            DFS(i, -1, tEnt, anc, puentes, g);
        }
    }
    cout << puentes.size() << "\n";
    for(auto[u,v] : puentes){
        cout << u << " " << v << "\n";
    }
    return 0; 
}