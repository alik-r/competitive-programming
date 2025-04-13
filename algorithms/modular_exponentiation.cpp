using ll = long long;

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
