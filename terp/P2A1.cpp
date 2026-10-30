#include <bits/stdc++.h> 

#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)

using namespace std; 

int main(){
    FIN; 
    int n, m; 
    cin >> n >> m; 
    vector<vector<int>> L(n+1); 
    for(int i=0; i<m; i++){
        int a, b; 
        cin >> a >> b; 
        L[a].push_back(b);
        L[b].push_back(a);
    }
    vector<int> padre(n+1,-1);
    queue<int> cola; 
    cola.push(1);
    padre[1];

    while(!cola.empty()){
        int t = cola.front(); 
        cola.pop();
        if(t == n) break;
        for(int w : L[t]){
            if(padre[w] == -1){
                padre[w] = t;
                cola.push(w);
            }
        }
    }
    if(padre[n] == -1){
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    vector<int> camino; 
    int v = n;
    while(v != 1){
        camino.push_back(v);
        v = padre[v];
    } 
    camino.push_back(1);
    reverse(camino.begin(), camino.end());
    cout << camino.size() << "\n";
    for(int x : camino) cout << x << " "; 
    cout << "\n";
}