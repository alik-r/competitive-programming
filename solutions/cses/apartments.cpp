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

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> desired(n);
	for (int i = 0; i < n; i++) {
		cin >> desired[i];
	}

	vector<int> aparts(m);
	for (int i = 0; i < m; i++) {
		cin >> aparts[i];
	}

	sort(desired.begin(), desired.end());
	sort(aparts.begin(), aparts.end());

	int count = 0;
	for (int i = 0, j = 0; i < n && j < m;) {
		if (abs(desired[i] - aparts[j]) <= k) {
			count++;
			i++;
			j++;
		} else if (desired[i] - aparts[j] > k) {
			j++;
		} else {
			i++;
		}
	}

	cout << count << '\n';
}
