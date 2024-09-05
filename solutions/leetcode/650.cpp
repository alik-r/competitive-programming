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

int min(int a, int b) {
	return (a < b) ? a : b;
}

int minSteps(int n) {
	vector<int> dp(n + 1, 1000);
	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= floor(i / 2); j++) {
			if (i % j == 0) {
				dp[i] = min(dp[i], dp[j] + floor(i / j));
			}
		}
	}

	return dp[n];
}

int main() {
	setIO();
}
