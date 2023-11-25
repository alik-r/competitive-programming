#include <iostream>
using namespace std;

int phi(int n) {
    int result = n; 

    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }

    if (n > 1) {
        result -= result / n;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The value of Euler's Phi function for " << n << " is " << phi(n) << '\n';
}

