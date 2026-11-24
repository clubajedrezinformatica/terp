#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std; 

int main(){
    FIN; 
    int n, k; 
    cin >> n >> k; 
    vector <int> a(n), q(k);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int j=0; j<k; j++) cin >> q[j];
    for(int x=0; x<k; x++){
        bool esta = false;
        for(int y=0; y<n; y++){
            
            if(a[y] == q[x]){
                esta = true;
            }
        }
        if (esta) cout << "YES\n"; else cout << "NO\n";
    }
}