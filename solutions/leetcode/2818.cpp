using ll = long long;

class Solution {
public:
    static ll modpow(ll base, ll exp, ll mod) {
        ll ans = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return ans;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        const int MOD = 1000000007;
        ll ans = 1;

        vector<int> primeScore(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int score = 0;
            for (int j = 2; j <= (int)sqrt(num); j++) {
                if (num % j == 0) {
                    score++;
                    while (num % j == 0) {
                        num /= j;
                    }
                }
            }
            if (num >= 2) {
                score++;
            }
            primeScore[i] = score;
        }

        vector<int> left(n, -1);
        vector<int> right(n, n);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeScore[st.top()] < primeScore[i]) {
                int idx = st.top();
                st.pop();
                right[idx] = i;
            }

            if (!st.empty()) {
                left[i] = st.top();
            }

            st.push(i);
        }

        priority_queue<array<int, 2>> maxHeap;
        for (int i = 0; i < n; i++) {
            array<int, 2> arr = {nums[i], i};
            maxHeap.push(arr);
        }

        while (k > 0) {
            array<int, 2> arr = maxHeap.top();
            maxHeap.pop();
            int num = arr[0];
            int idx = arr[1];
            int score = primeScore[idx];

            ll l = idx - left[idx];
            ll r = right[idx] - idx;

            ll cnt = l * r;
            ll ops = min(cnt, (ll)k);
            ans = (ans * modpow(num, ops, MOD)) % MOD;
            k -= ops;
        }

        return ans;
    }
};
