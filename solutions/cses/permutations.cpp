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

	int n;
	cin >> n;

	if (n == 1) {
		cout << 1 << '\n';
	} else if (n < 4) {
		cout << "NO SOLUTION" << '\n';
	} else {
		for (int i = 2; i <= n; i += 2) {
			cout << i << " ";
		}

		for (int i = 1; i <= n; i += 2) {
			cout << i << " ";
		}

		cout << '\n';
	}
}
