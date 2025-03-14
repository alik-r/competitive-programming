class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1;
        int r = 0;
        for (int c : candies) r = max(r, c);
        int ans = 0;

        while (l <= r) {
            int m = l + (r - l) / 2;
            long long cnt = 0;

            for (int c : candies) cnt += c / m;

            if (cnt >= k) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};
