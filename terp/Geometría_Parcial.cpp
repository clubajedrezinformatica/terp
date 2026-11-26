#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std; 

struct P{
    long long x, y;
};

long long cross(P a, P b, P c){
    return(b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main(){
    FIN; 
    int n; 
    cin >> n;
    long long colineales = 1;
    vector<P> planetas(n);
    for(int i=0; i<n; i++) cin >> planetas[i].x >> planetas[i].y;
    for(int j=0; j<n; j++){

    }
}