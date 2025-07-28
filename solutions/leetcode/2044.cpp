class Solution1 {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        for (int i = 0; i < n; i++) maxOr |= nums[i];

        int count = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            int currentOr = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    currentOr |= nums[i];
                }
            }
            if (currentOr == maxOr) count++;
        }
        return count;
    }
};

class Solution2 {
public:
    void dfs(int start, const vector<int>& nums, int maxOr, int currentOr, int& count, int size) {
        if (size > 0 && currentOr == maxOr) {
            count++;
        }

        for (int i = start; i < nums.size(); i++) {
            dfs(i + 1, nums, maxOr, currentOr | nums[i], count, size + 1);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int i = 0; i < nums.size(); i++) maxOr |= nums[i];

        sort(nums.begin(), nums.end());
        int count = 0;
        dfs(0, nums, maxOr, 0, count, 0);
        return count;
    }
};
