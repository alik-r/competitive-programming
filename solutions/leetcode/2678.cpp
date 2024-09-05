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

int countSeniors(vector<string>& details) {
	int count = 0;
	for (string d : details) {
		count += stoi(d.substr(11, 2)) > 60;
	}
	return count;
}

int main() {
	setIO();
}
