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

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
	vector<vector<int>> sol;

	if (m * n != original.size()) return sol;

	vector<int> row;
	for (int i = 0; i < (int)original.size(); i++) {
		row.push_back(original[i]);
		if ((i + 1) % n == 0) {
			sol.push_back(row);
			row.clear();
		}
	}

	return sol;
}

void print2DArray(vector<vector<int>> arr2D) {
	for (int i = 0; i < arr2D.size(); i++) {
		for (int j = 0; j < arr2D[i].size(); j++) {
			cout << arr2D[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	setIO();
	
	vector<int> v = {1, 2, 3, 4};
	vector<vector<int>> sol = construct2DArray(v, 2, 2);
	print2DArray(sol);
}
