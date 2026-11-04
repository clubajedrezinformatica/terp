#include <bits/stdc++.h> 

using namespace std; 

#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)

bool test(int dist, int k, vector<int>& v){
    int last = v[0];
    int cont = 1; 
    for(int i=1; i<v.size();i ++){
        if(v[i] - last >= dist){
            cont++;
            last = v[i];
        }
    }
    if (cont >= k) return true;
    else return false;  
}

int main(){
    FIN; 
    int n, k; 
    cin >> n >> k; 
    vector<int> v(n); 
    for(int i=0; i<n; i++) cin >> v[i]; 
    int l=0;//valor que siempre vale; 
    int r=v.back()+1;//el +1 es importante: el valor nunca es válido
    while(r-l > 1){
        int med = (l+r)/2; 
        bool check = test(med, k, v); 
        if(check){
            l = med; 
        }else{
            r = med;
        }
    }
    cout << l << "\n";
}
//IMPORTANTE: es necesario definir correctamente las cotas o límites izquierdo - l - y derecho - r; el TEST INICIAL: siempre vale (en este caso, 0); el TEST FINAL nunca vale (en este caso v.back + 1 - la última posición en el arreglo + 1 - saliendo del rango posible del vector). EL TEST ES LO QUE CAMBIA ENTRE EJERCICIO Y EJERCICIO.   