#include <bits/stdc++.h> 
using namespace std; 
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)

typedef long long ll; 

vector<int> padre, tamano; 

int find(int x){
    if (padre[x] == x) return x; 
    return padre[x] = find(padre[x]);
}

bool unir(int a, int b) {
    a = find(a); 
    b = find(b);
    if(a == b) return false; 
    if(tamano[a] < tamano[b]) swap(a, b); 
    padre[b] = a; 
    tamano[a] += tamano[b];
    return true; 
}

int main(){
    FIN; 
    int n, m; 
    cin >> n >> m; 

    vector<tuple<int,int,int>> aristas(m);
    for(int i=0; i<m; i++){
        int a,b,c; 
        cin >> a >> b >> c; 
        aristas[i] = {c,a,b};
    }
    sort(aristas.begin(), aristas.end());

    padre.resize(n+1);
    tamano.assign(n+1, 1);
    for(int i=1; i<=n; i++) padre[i] = i;

    ll costo_total = 0; 
    int aristas_usadas = 0; 

    for(auto[c, u, v] : aristas){
        if(unir(u,v)){
            costo_total += c; 
            aristas_usadas++; 
            if(aristas_usadas == n-1) break;
        }
    }
    if(aristas_usadas < n-1){
        cout << "IMPOSSIBLE" << "\n";
    }else{
        cout << costo_total << "\n";
    }
    return 0; 
}
