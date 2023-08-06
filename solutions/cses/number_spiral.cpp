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

	int t; 
	cin >> t;
	while (t--) {
		ll y, x, ans;
		cin >> y >> x;
		if (x > y) {
			if (x % 2 != 0) {
				ans = x * x - y + 1;
			} else {
				x--;
				ans = x * x + y;
			}
		} else {
			if (y % 2 == 0) {
				ans = y * y - x + 1;
			} else {
				y--;
				ans = y * y + x;
			}
		}
		cout << ans << '\n';
	}
}
