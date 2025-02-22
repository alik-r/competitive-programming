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
    setIO("shell");

    int n;
    cin >> n;
    
    vector<int> v = {1, 2, 3};
    vector<int> wins(3, 0);
    for (int i = 0; i < n; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        a--, b--, g--;
        swap(v[a], v[b]);
        wins[g]++;
    }

    int res = max(wins[0], max(wins[1], wins[2]));
    cout << res << '\n';
}
