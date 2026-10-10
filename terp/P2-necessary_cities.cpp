const int INF = 1e9+7;
int tiempo = 0; 
int DFS(int cur, vector<int> &tEnt, vector<int> &anc, vector<bool> &puntoArt,... hay que pasar el grafo){
    tEnt[cur] = tiempo;
    anc[cur] = tiempo; 
    tiempo++; 
    int hijos = 0;
    for(int next : g[cur]){
        if(next == p) continue;
        if(tEnt[next] == -1){ // encontramos un forward
            hijos++;
            DFS(next, tEnt, anc, puntoArt, g, cur);
            if(anc[next] >= tEnt[cur]){
                puntoArt[cur] = true; 
            }
            anc[cur] = min(anc[cur], anc[next]);
        }else{//encontramos back edge
            anc[cur] = tEnt[next];
        }
    }
    return hijos;

}
int main(){
    FIN;
    int n, m; 
    cin >> n >> m; 
    vector <vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u , v;
        cin >> u >> v; 
        u..M v..M 
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <int> tEnt(n, -1), anc(n, INF);
    vector <bool> puntoArt(n, false);
    for(int i = 0; i < n; i++){
        if(tEnt[i] == -1){
            puntoArt[i] = DFS(i, tEnt, anc, puntoArt) > 1;    
        }
    }
    for(int i = 0; i < n; i++){
        if(puntoArt[i] == true) ans.push_back(i+1);
    }
    //revisar el final de este ejercicio
    return 0; 
}