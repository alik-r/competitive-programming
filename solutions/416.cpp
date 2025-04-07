class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }

        int target = sum / 2;
        unordered_set<int> dp;
        dp.insert(0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            unordered_set<int> next = (dp);
            for (auto it = dp.begin(); it != dp.end(); it++) {
                if (*it + nums[i] == target) {
                    return true;
                }
                next.insert(*it + nums[i]);
            }
            dp = next;
        }
        return dp.count(target) > 0;
    }
};
