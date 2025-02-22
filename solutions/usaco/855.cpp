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

vector<int> cap(3);
vector<int> cur(3);

void pour(int from, int to) {
    int amount = min(cur[from], cap[to] - cur[to]);
    cur[from] -= amount;
    cur[to] += amount;
}

int main() {
    setIO("mixmilk");

    int from = 0;
    for (int i = 0; i < 3; i++) {
        int capacity, current;
        cin >> capacity >> current;
        cap[i] = capacity;
        cur[i] = current;
    }

    for (int i = 0; i < 100; i++) {
        pour(from, (from + 1) % 3);
        from = (from + 1) % 3;
    }

    for (int i = 0; i < 3; i++) {
        cout << cur[i] << '\n';
    }
}
