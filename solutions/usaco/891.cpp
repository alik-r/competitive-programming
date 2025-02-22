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
    
    int first = 0;
    int second = 0;
    int third = 0;
    vector<int> v = {1, 2, 3};
    for (int i = 0; i < n; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        a--;
        b--;
        g--;
        swap(v[a], v[b]);
        first += int(v[g] == 1);
        second += int(v[g] == 2);
        third += int(v[g] == 4);
    }

    int res = max(first, max(second, third));
    cout << res << '\n';
}
