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
    setIO("cowsignal");

    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<char>> v(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            v[i][j] = c;
        }
    }

    for (int i = 0; i < k*m; i++) {
        for (int j = 0; j < k*n; j++) {
            cout << v[i / k][j / k];
        }
        cout << '\n';
    }
}
