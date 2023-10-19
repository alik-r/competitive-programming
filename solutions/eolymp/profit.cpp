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

int max(int a, int b) {
	return (a > b) ? a : b;
}

int kadane(const vector<int> &arr) {
	int ans = arr[0];
	int current = arr[0];

	for (size_t i = 1; i < arr.size(); i++) {
		current = max(current + arr[i], arr[i]);
		ans = max(ans, current);
	}

	return ans;
}

int main() {
	setIO();
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << kadane(arr) << '\n';
}
