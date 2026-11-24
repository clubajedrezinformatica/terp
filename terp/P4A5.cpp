#include <bits/stdc++.h>
#define FIN ios::syncwithstdio(0); cout.tie(0); cin.tie(0)
using namespace std; 

int main(){
    long long n, t; //n=machines, t=products
    cin >> n >> t;  
    vector<long long> times(n+1);
    for(int i=1; i<=n; i++) cin >> times[i];
    long long possible_time = times[1] * t;  
    int answer;
    for(int j=1; j<=possible_time; j++){
        long long time = 0;
        for(int x=1; x<=n;x++){
            time+=j/times[x];
        }
        if(time >= t){
            answer = j;
            break;
        }
    }
    cout << answer << '\n'; // tiene que ser 8
}