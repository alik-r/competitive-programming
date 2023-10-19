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

int p(int x) {
	int ans = 1;
	while (x != 0) {
		ans *= x % 10;
		x /= 10;
	}
	return ans;
}

int foo(int n) {
	int idx = 0;
	while (n > 9) {
		n = p(n);
		idx++;
	}
	return idx;
}

int main() {
	setIO();
	int n;
	while (cin >> n) {
		cout << foo(n) << '\n';
	}
}
