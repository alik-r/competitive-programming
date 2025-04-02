class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        using ll = long long;

        size_t n = nums.size();
        ll ans = 0;

        ll maxLeft = nums[0];
        ll maxDiff = numeric_limits<ll>::min();

        for (int i = 1; i < n - 1; i++) {
            maxDiff = max(maxDiff, maxLeft - nums[i]);
            maxLeft = max(maxLeft, (ll)nums[i]);
            ans = max(ans, maxDiff * nums[i + 1]);
        }

        return ans;
    }
};
