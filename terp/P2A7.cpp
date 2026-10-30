#include <bits/stdc++.h> 
using namespace std; 

#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)

const int INF = 1e9+7;
int tiempo = 0; 

int DFS(int cur, int p, vector<int>& tEnt, vector<int>& anc, vector<bool>& puntoArt, vector<vector<int>>& g){
    tEnt[cur] = tiempo; 
    anc[cur] = tiempo; 
    tiempo++; 
    int hijos = 0; 
    for(int next : g[cur]){
        if(next == p) continue; 
        if(tEnt[next] == -1){
            hijos++; 
            DFS(next, cur, tEnt, anc, puntoArt, g);
            if(anc[next] >= tEnt[cur]){
                puntoArt[cur] = true;
            }
            anc[cur] = min(anc[cur], anc[next]);
        }else{
            anc[cur] = min(anc[cur], tEnt[next]);
        }
    }
    return hijos; 
}

int main(){
    FIN; 
    int n,m; 
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
    vector<bool> puntoArt(n, false);
    for(int i=0; i<n; i++){
        if(tEnt[i] == -1){
            int hijos = DFS(i, -1, tEnt, anc, puntoArt, g);
            puntoArt[i] = (hijos > 1);
        }
    }

    vector<int> ans;
    for(int i=0; i<n; i++){
        if(puntoArt[i]) ans.push_back(i+1);
    } 

    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}