#include <bits/stdc++.h>

using namespace std; 
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int main(){
    FIN; 
    int n, k, next_round = 0;
    cin >> n >> k;
    vector<int> scores(n);
    for(int i = 0; i < n; i++){
        cin >> scores[i];
    } 
    int puntaje_k = scores[k - 1];

    for(int i = 0; i < n; i++){
        if(scores[i] >= puntaje_k && scores[i] > 0){
            next_round++;
        }
    }  
    cout << next_round;
    return 0;
}