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
        setIO("blist");
        vector<int> time(1001);
        int n;
        cin >> n;
        int tmin = 1000;
        int tmax = 1;
        for (int i = 0; i < n; i++) {
                int start, end, buckets;
                cin >> start >> end >> buckets;
                time[start] = buckets;
                time[end] = -buckets;
                tmin = min(tmin, start);
                tmax = max(tmax, end);
        }

        int total = 0;
        int ans = 0;
        for (int i = tmin; i <= tmax; i++) {
                total += time[i];
                ans = max(ans, total);
        }
        cout << ans << '\n';
}
