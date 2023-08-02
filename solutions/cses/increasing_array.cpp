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

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	unsigned long long ans = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			ans += 1ull * arr[i - 1] - arr[i];
			arr[i] = arr[i - 1];
		}
	}

	cout << ans << '\n';
}
