#include <bits/stdc++.h>
#include <string> 

using namespace std; 
#define FIN ios::sync_with_stdio(0);cout.tie(0); cin.tie(0);

int main(){
    FIN; 
    int x = 0; 
    int n; 
    cin >> n; 
    string operation; 
    for(int i = 0; i < n; i++){
        cin >> operation;
        if(operation[1] == '+'){
            x++;
        }else{
            x--;
        }
    }
    cout << x; 
    return 0;
}