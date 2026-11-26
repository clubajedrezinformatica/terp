#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std; 

struct P{
    long long x, y;
};

long long cross(P a, P b, P c){
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)* (b.y - a.y);
}

int main(){
    FIN; 
    int t; 
    cin >> t; 
    for(int i=0; i<t; i++){
        P a, b, c; 
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        long long cruz = cross(a, b, c); 
        if(cruz > 0){
            cout << "LEFT" << '\n';
        }else if(cruz < 0) cout << "RIGHT" << '\n';
        else cout << "TOUCH" << '\n';
    }
}