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

int main() {
	setIO();
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	char arr[n * a][m * b];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char color;
			cin >> color;
			for (int k = i * a; k < i * a + a; k++) {
				for (int p = j * b; p < j * b + b; p++) {
					arr[k][p] = color;
				}
			}
		}
	}

	for (int i = 0; i < n * a; i++) {
		for (int j = 0; j < m * b; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}
