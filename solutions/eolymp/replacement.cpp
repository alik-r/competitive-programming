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
	setIO();

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<int> s;
    vector<int> ans(n);

    for (int i = n-1; i >= 0; i--) {
        while (!s.empty() && s.top() <= a[i]) {
            s.pop();
        }

        if (s.empty()) {
            ans[i] = 0;
        } else {
            ans[i] = s.top();
        }

        s.push(a[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}
