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

void foo(string str, int n) {
	if (n == 0) {
		cout << str << '\n';
		return;
	}

	if (str.empty()) {
		foo(str + "0", n - 1);
	} else {
		foo(str + " 0", n - 1);
	}

	if (str.empty()) {
		foo(str + "1", n - 1);
	} else if (str.back() != '1') {
		foo(str + " 1", n - 1);
	}	
}

int main() {
	setIO();
	int n;
	cin >> n;
	foo("", n);
}
