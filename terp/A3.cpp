#include <bits/stdc++.h>

using namespace std; 

#define FIN ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main(){
    FIN; 

    int n;  
    int total = 0;
    int puntajeIndividual;
    int puntajeEquipo;
    
    cin >> n; 

    for (int i = 0; i < n; i++){
        int puntajeEquipo = 0; 
        for (int j = 0; j < 3; j++){
            cin >> puntajeIndividual;
            puntajeEquipo += puntajeIndividual;
        }
        if(puntajeEquipo > 1){
            total++;
        }
    }
    cout << total;
    
    return 0;
}