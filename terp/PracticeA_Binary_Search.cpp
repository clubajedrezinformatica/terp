#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std; 

int main(){
    FIN;
    int n, k; 
    cin >> n >> k; 
    vector<int> a(n); 
    vector<int> q(k);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int j=0; j<k; j++) cin >> q[j];
    for(int z=0; z < k; z++){
        int L=-1, R=n;
        while(R-L > 1){
            int mid = L + (R-L)/2;
            if(q[z]>a[mid]) L = mid;
            else R = mid;  
        }
        if(R < n && a[R] == q[z]) cout << "YES\n"; else cout << "NO\n"; 
    }
}