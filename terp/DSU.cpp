#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

vector<int> p, rnk;                // rnk: "rank" choca con std::rank

void makeSets(int n) {
    p.resize(n); rnk.assign(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;        // cada elemento es su propio padre
}

int findSet(int x) {
    if (x != p[x]) p[x] = findSet(p[x]);         // path compression
    return p[x];
}

bool sameSet(int x, int y) { return findSet(x) == findSet(y); }

void unionSet(int x, int y) {
    int r = findSet(x), s = findSet(y);
    if (r == s) return;
    if (rnk[r] < rnk[s]) swap(r, s);             // r queda con el rank mayor
    p[s] = r;                                    // el de menor rank cuelga del mayor
    if (rnk[r] == rnk[s]) rnk[r]++;
}

int main() {
    FIN;
    makeSets(5);
    unionSet(0, 1);
    unionSet(3, 2);
    unionSet(4, 3);
    unionSet(3, 0);
    cout << (sameSet(1, 4) ? "mismo conjunto" : "distinto") << '\n';
    for (int i = 0; i < 5; i++) cout << p[i] << ' ';
    cout << '\n';
    for (int i = 0; i < 5; i++) cout << rnk[i] << ' ';
    cout << '\n';
}