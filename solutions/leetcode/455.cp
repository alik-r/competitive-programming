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

int solve(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());

	int gIdx = 0;
	int sIdx = 0;
	while (gIdx < g.size() && sIdx < s.size()) {
		if (s[sIdx] >= g[gIdx]) {
			gIdx++;
		}
		sIdx++;
	}
	return gIdx;
}

int main() {
	setIO();
}
