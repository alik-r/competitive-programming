class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp;
        for (int i = 0; i < nums.size(); i++) {
            dp.push_back({nums[i]});
        }
        int ans = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] % nums[i] == 0) {
                    vector<int> tmp = { nums[i] };
                    tmp.insert(tmp.end(), dp[j].begin(), dp[j].end());
                    if (tmp.size() > dp[i].size()) {
                        dp[i] = tmp;
                    }
                }
            }
            if (dp[i].size() > dp[ans].size()) {
                ans = i;
            }
        }
        return dp[ans];
    }
};
