#include <bits/stdc++.h> 
#define FIN ios::syncwithstdio(0); cout.tie(0); cin.tie(0)
using namespace std; 

long long n, t; 

bool can(long long dt, vector<long long>&times){
    long long total = 0;
    for(int i=0; i<n;i++){
        total+=dt/times[i];
        if(total >= t){//guarda que evita el overflow
            return true;
        }
    }
    return (total >= t);
}

int main(){ 
    cin >> n >> t; 
    vector<long long> times(n);
    for(int i=0; i<n;i++) cin >> times[i];
    long long L=0, R=times[0]*t;
    while(R-L > 1){
        long long mid = L+(R-L)/2; 
        if (can(mid, times)) R = mid;
        else L = mid;
    }
    cout << R << '\n';
}