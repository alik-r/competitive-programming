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

	long long n;
	cin >> n;
	
	while (n != 1) {
		cout << n << " ";
		if (n % 2 == 0) {
			n /= 2;
		} else {
			n *= 3;
			n++;
		}
	}

	cout << n << '\n';
}
