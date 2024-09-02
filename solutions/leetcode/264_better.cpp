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


int nthUglyNumber(int n) {
	vector<ull> v = {1};
	int i2 = 0, i3 = 0, i5 = 0;

	for (int i = 1; i < n; i++) {
		ull next = min(v[i2] * 2, min(v[i3] * 3, v[i5] * 5));
		v.push_back(next);

		if (next == v[i2] * 2) {
			i2++;
		}
		if (next == v[i3] * 3) {
			i3++;
		}
		if (next == v[i5] * 5) {
			i5++;
		}
	}

	return v[n - 1];
}

int main() {
	setIO();

	for (int i = 1; i <= 10; i++) {
		cout << nthUglyNumber(i) << " ";
	}
	cout << '\n';
}
