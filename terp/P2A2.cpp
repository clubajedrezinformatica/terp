#include <bits/stdc++.h>

using namespace std; 

typedef long long ll; 
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)

struct DSU {
    vector<int> link, tam; 
    vector<vector<int>> comp; 
    DSU(){}
    DSU(int n){
        link.resize(n+1); tam.resize(n+1,1);
        comp.resize(n+1);
        for(int i=1; i<=n; i++){
            link[i] = i; 
            comp[i].push_back(i);
        }
    }
    void join(int u, int v){
        u = link[u];
        v = link[v]; 
        if(u == v) return; 
        if(tam[v] > tam[u]) swap(u, v);
        for(int nodo : comp[v]){
            link[nodo] = u; 
            comp[u].push_back(nodo);
        }
        tam[u] += tam[v];
        tam[v] = 0;
        comp[v].clear();
    }

    bool same(int u, int v){
        return link[u] == link[v];
    }

    int findLink(int u){
        return link[u];
    }

    int calcTam(int u){
        return tam[link[u]];
    }
};

int main(){
    FIN; 

    int n, m; 
    cin >> n >> m; 
    DSU dsu(n);
    int comp = n, maxTam = 1; 
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v; 
        if(!dsu.same(u,v)) comp--; 
        dsu.join(u,v);
        maxTam = max(maxTam, dsu.calcTam(u));
        cout << comp << " " << maxTam << "\n";
    }
    return 0;
}