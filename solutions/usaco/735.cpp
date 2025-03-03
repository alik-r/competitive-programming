#include "bits/stdc++.h"
using namespace std;

using ll = long long; 
using ull = unsigned long long;
using ld = long double;

void setIO(string name = "") {
        cin.tie(nullptr)->sync_with_stdio(false); 
        if ((int)name.size()) {
                freopen((name + ".in").c_str(), "r", stdin);
                freopen((name + ".out").c_str(), "w", stdout);
        }
}

int main() {
    setIO("lostcow");
    int x, y;
    cin >> x >> y;
    int dist = 0;
    int dir = 1;
    int step = 1;
    int initX = x;
    while (true) {
        for (; x != y && x != initX + dir * step; x += dir) dist++;
        if (x == y) break;
        dir *= -1;
        step *= 2;
    }
    cout << dist << '\n';
}
