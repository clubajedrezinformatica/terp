#include <bits/stdc++.h>

using namespace std; 

typedef long long ll; 
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
const int INF = 1e9+7; 

int proximoOrden = 0; 

int DFS(int actual, vector<int> &ordenVisita, vector<int> &minAlcanzable, vector<bool> &esArticulacion, vector<pair<int,int>> &puentes, vector<vector<int>> &g, int padre = -1){
    ordenVisita[actual] = proximoOrden;
    minAlcanzable[actual] = proximoOrden;
    proximoOrden++;
    int hijos = 0; 
    for(int vecino : g[actual]){
        if(vecino == padre) continue;
        if(ordenVisita[vecino] == -1){
            hijos++; 
            DFS(vecino, ordenVisita, minAlcanzable, esArticulacion, puentes, g, actual);
            if(minAlcanzable[vecino] >= ordenVisita[actual]) esArticulacion[actual] = true;
            if(minAlcanzable[vecino] > ordenVisita[actual]) puentes.push_back({actual, vecino});
            minAlcanzable[actual] = min(minAlcanzable[actual], minAlcanzable[vecino]);
        }else{
            minAlcanzable[actual] = min(minAlcanzable[actual], ordenVisita[vecino]);
        }
    }
    return hijos; 
}
int main(){
    FIN;
    int n, m; 
    cin >> n >> m; 
    vector<vector<int>> g(n+1);
    for(int i=0; i<m; i++){
        int u, v; 
        cin >> u >> v; 
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> ordenVisita(n+1,-1), minAlcanzable(n+1,INF);
    vector<bool> esArticulacion(n+1,false);
    vector<pair<int, int>> puentes; 
    for(int i=1; i<=n; i++){
        if(ordenVisita[i] == -1){
            esArticulacion[i] = (DFS(i, ordenVisita, minAlcanzable, esArticulacion, puentes, g) > 1);
        }
    }
    vector<int> articulaciones; 
    for(int i=1; i<=n; i++){
        if(esArticulacion[i]) articulaciones.push_back(i);
    }
    cout << articulaciones.size() << "\n";
    for(int v : articulaciones) cout << v << " ";
    cout << "\n";
    cout << puentes.size() << "\n";
    for(auto[u, v] : puentes) cout << u << " " << v << "\n";
    return 0;
}