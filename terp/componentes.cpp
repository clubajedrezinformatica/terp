#include <bits/stdc++.h>

using namespace std; 

typedef long long ll; 
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)

void DFS(int cur, int c, vector<int> &comp, vector<vector<int>> &g){
    comp[cur] = c; 
    for(int next : g[cur]){
        if(comp[next] == 0) DFS(next, c, comp, g);
    }
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
    vector<int> comp(n+1, 0);
    int numCC = 0;
    for(int i=1; i<=n; i++){
        if(comp[i] == 0){
            numCC++;
            DFS(i,numCC,comp,g);
        }
    }
    cout << numCC << "\n";
    return 0;
}