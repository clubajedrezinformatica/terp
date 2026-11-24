#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std; 

int main(){
    FIN;
    int w, h, n, answer; 
    cin >> w >> h >> n;
    int L = 0, R = max(w*n,h);
    for(int i=L; i <= R; i++){
        if (((i/w)*(i/h)) >= n){
            answer = i;
            break;
        }

    } 
    cout << answer << '\n';
}