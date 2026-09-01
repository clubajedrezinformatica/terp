#include <bits/stdc++.h>

using namespace std; 

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

int main(){
    FIN; 
    int pesoSandia; 
    cin >> pesoSandia;
    if(pesoSandia%2 == 0 and pesoSandia > 2){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

    return 0; 
}