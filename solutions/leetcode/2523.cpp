class Solution {
public:
    vector<char> segmentedSieve(long long L, long long R) {
        long long lim = sqrt(R);
        vector<char> mark(lim + 1, false);
        vector<long long> primes;
        for (long long i = 2; i <= lim; ++i) {
            if (!mark[i]) {
                primes.emplace_back(i);
                for (long long j = i * i; j <= lim; j += i)
                    mark[j] = true;
            }
        }

        vector<char> isPrime(R - L + 1, true);
        for (long long i : primes)
            for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
                isPrime[j - L] = false;
        if (L == 1)
            isPrime[0] = false;
        return isPrime;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<char> isPrime = segmentedSieve(left, right);
        vector<int> ans(2, -1);
        int lastPrime = -1;
        int minDiff = right;
        for (int i = left; i <= right; i++) {
            if (isPrime[i - left]) {
                if (lastPrime != -1) {
                    int curDiff = i - lastPrime;
                    if (curDiff < minDiff) {
                        minDiff = curDiff;
                        ans = {lastPrime, i};
                    }
                }
                lastPrime = i;
            }
        }
        return ans;
    }
};
