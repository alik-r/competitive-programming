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
	int k, n, w;
	cin >> k >> n >> w;

	ll sum = (ll)k * w * (w + 1) / 2;

	cout << max(0ll, sum - n) << '\n';

}
