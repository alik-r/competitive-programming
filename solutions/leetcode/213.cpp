class Solution {
public:
    int robInLine(vector<int>& nums, int l, int r) {
        int n = r - l + 1;
        if (n == 1) return nums[l];
        vector<int> dp(n, 0);
        dp[0] = nums[l];
        dp[1] = max(dp[0], nums[l + 1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[l + i]);
        }
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robInLine(nums, 0, n - 2), robInLine(nums, 1, n - 1));
    }
};
