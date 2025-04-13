using ll = long long;

class Solution {
public:
    ll modexp(ll base, ll exp, ll mod) {
        base %= mod;
        ll ans = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                ans = ans * base % mod;
            }
            base = base * base % mod;
            exp /= 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        ll mod = 1e9 + 7;
        ll odd = floor(n / 2.0);
        ll even = ceil(n / 2.0);
        cout << odd << " " << even << endl;
        ll ans = modexp(4, odd, mod) * modexp(5, even, mod) % mod;
        return ans;
    }
};
