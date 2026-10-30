#include <bits/stdc++.h>

using namespace std; 

#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)

vector<int> padre, tamano; 

int find(int x) {
    if(padre[x] == x) return x; 
    return padre[x] = find(padre[x]);
}

bool unir(int a, int b){
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

    padre.resize(n+1);
    tamano.assign(n+1, 1);
    for(int i=1; i<=n; i++) padre[i] = i;
    for(int i=0; i<m; i++){
        int a, b; 
        cin >> a >> b; 
        unir(a, b);
    }
    //Recolecta un representante por cada componente 
    vector<int> representantes; 
    for(int i=1; i<=n; i++){
        if(find(i) == i){
            representantes.push_back(i);
        }
    }

    int k = (int)representantes.size() - 1; 
    cout << k << "\n"; 
    for(int i=0; i<k; i++){
        cout << representantes[i] << " " << representantes[i+1] << "\n"; 
    }
    return 0;
}