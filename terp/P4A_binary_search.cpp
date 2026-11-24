#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std; 

long long w, h, n; 

bool alcanza(long long x){
    //si x/w >= n AND x/h >= 1 ya alcanza 
    if(x/w >= n && x/h >= 1) return true; 
    else{
        if(x/w >= 1 && x/h >= n) return true;
        else return ((x/w)*(x/h)) >= n;
    }
    
}

int main(){
    FIN;
    cin >> w >> h >> n; 
    long long L = 0, R = max(w*n, h);     
    while(R-L > 1){
        long long mid = L + (R-L)/2;
        if (alcanza(mid)){
            R = mid; 
        }else{
            L = mid;
        }
    }
    cout << R << '\n';
}