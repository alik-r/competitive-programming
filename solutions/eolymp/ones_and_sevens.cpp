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
	    
	ll n;
    cin >> n;

    int len = 1;
    ll total = 2;  

    while (n > total) {
        n -= total;
        len++;
        total = pow(2, len);
    }

    n--;

    string result = "";
    while (len--) {
        if (n & 1) {
            result = "7" + result;
        } else {
            result = "1" + result;
        }
        n >>= 1;
    }

    cout << result << '\n';
}
