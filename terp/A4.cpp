#include <bits/stdc++.h>

using namespace std; 

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

int main() {
    long long ancho, largo;
    cin >> ancho;
    cin >> largo;

    long long baldosa;
    cin >> baldosa;

    long long baldosas_ancho = (ancho + baldosa - 1) / baldosa;
    long long baldosas_largo = (largo + baldosa - 1) / baldosa;

    long long total = baldosas_ancho * baldosas_largo;

    cout << total << '\n';

    return 0;
}