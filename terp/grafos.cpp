#include <bits/stdc++.h>

using namespace std; 

typedef long long ll; 
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
const ll INF = 1e18+7;

struct Arista {
    int from, to, w; 
    Arista(){}
    Arista(int _from, int _to, int _w){
        from = _from, to = _to, w = _w;
    }
};

int main(){
    FIN; 

    int n,m; 
    cin >> n >> m; 
    vector<vector<Arista>> g(n+1);
    vector<vector<ll>> mat(n+1,vector<ll>(n+1, INF));
    vector <Arista> aristas; 
    for(int i=1; i<=n; i++) mat[i][i] = 0;
    for(int i=0; i<m; i++){
        int u, v, w; 
        cin >> u >> v >> w; 
        g[u].push_back(Arista(u,v,w));
        g[v].push_back(Arista(v,u,w));
        mat[u][v] = min(mat[u][v], (ll)w);
        mat[v][u] = min(mat[v][u], (ll)w);
        aristas.push_back(Arista(u,v,w));
    }

    cout << "lista de adyacencia\n";
    for(int u=1; u<=n; u++){
        cout << u << " (grado" << g[u].size() << "):";
        for(Arista a : g[u]) cout << " " <<  a.to << "/" << a.w; 
        cout << "\n";
    }

    cout << "matriz de adyacencia\n";
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n;j++){
            if(mat[i][j] == INF) cout << "INF ";
            else cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "lista de aristas\n";
    for(Arista a: aristas) cout << a.from << " " << a.to << " " << a.w << "\n";
    return 0; 
}
