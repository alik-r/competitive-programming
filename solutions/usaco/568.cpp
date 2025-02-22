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
    setIO("speeding");

    int n, m;
    cin >> n >> m;
    vector<int> limit(101);
    int current = 0;
    for (int i = 0; i < n; i++) {
        int len, lim;
        cin >> len >> lim;
        for (int j = current + 1; j <= current + len; j++) limit[j] = lim;
        current += len;
    }

    int maxdiff = 0;
    current = 0;
    for (int i = 0; i < m; i++) {
        int len, speed;
        cin >> len >> speed;
        for (int j = current + 1; j <= current + len; j++) maxdiff = max(maxdiff, speed - limit[j]);
        current += len;
    }

    cout << maxdiff << '\n';
}
