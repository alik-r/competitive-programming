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
        setIO("shuffle");

        int n;
        cin >> n;
        vector<int> order(n);
        vector<int> after(n);

        for (int i = 0; i < n; i++) {
                cin >> order[i];
                order[i]--;
        }

        for (int i = 0; i < n; i++) cin >> after[i];

        for (int i = 0; i < n; i++) {
                int idx = i;
                for (int j = 0; j < 3; j++) idx = order[idx];
                cout << after[idx] << '\n';
        }
}
