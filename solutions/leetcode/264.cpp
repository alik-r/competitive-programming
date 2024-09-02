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
	ull dp[1691];
	ull f[] = {2, 3, 5};
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		ull minn = dp[i - 1] * 5;
		ull current = minn;
		for (int j = i - 1; j >= 1; j--) {
			for (int k = 2; k >= 0; k--) {
				current = dp[j] * f[k];
				if (current <= dp[i - 1]) break;
				minn = min(minn, current);
			}
		}
		dp[i] = minn;
	}

	return dp[n];
}

int main() {
	setIO();

	for (int i = 1; i <= 10; i++) {
		cout << nthUglyNumber(i) << " ";
	}
	cout << '\n';
}
