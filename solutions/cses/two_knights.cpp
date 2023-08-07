#include "bits/stdc++.h"
using namespace std;

using ll = long long; 
using ull = unsigned long long;
using ld = long double;

void setIO(string name = "") 
{
	cin.tie(nullptr)->sync_with_stdio(false); 
	if ((int)name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main()
{
	setIO();

	// total: k^2 * (k^2 - 1) / 2
	// to solve it, count number of 2x3 and 3x2 rectangles,
	// for kxk chessboard:
	// 2x3 = (k-1)(k-2)
	// 3x2 = (k-2)(k-1)
	// total attack rectangles = 2(k-1)(k-2)
	// then, there are two possible ways to attack in each rectangle
	// so, # of ways to attack: 4(k-1)(k-2)
	// ans = total - 4(k-1)(k-2)

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << 1ull*i*i*(i*i-1)/2 - 4*(i-1)*(i-2) << '\n';
	}
}
