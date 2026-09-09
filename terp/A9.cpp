#include <bits/stdc++.h>
#include <algorithm>

using namespace std; 

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

int main(){
    int n, a, b, c; 
    cin >> n >> a >> b >> c; 
    int max_piezas = 0; 
    for(int x = 0; x*a <= n; x++){
        for(int y = 0; x*a + y*b <= n; y++){
            int resto = n - x*a - y*b; 
            if(resto % c == 0){
                int z = resto / c; 
                int piezas = x+y+z; 
                max_piezas = max(max_piezas, piezas);
            }
        }

    }
    cout << max_piezas <<"\n";
    return 0;
}