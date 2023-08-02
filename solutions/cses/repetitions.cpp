#include "bits/stdc++.h"
using namespace std;

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

	string s;
	cin >> s;

	int cur = 1, ans = 1;

	for (size_t i = 1; i < s.size(); i++) {
		if (s[i] == s[i-1]) {
			cur++;
			ans = max(ans, cur);
		} else {
			cur = 1;
		}
	}

	cout << ans << '\n';
}
