class Solution {
public:

    int subsetXORSum(vector<int>& nums) {
        size_t n = nums.size();
        int ans = 0;

        for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
            int xorSum = 0;
            for (int i = 0; i < n; i++) {
                if (bitmask & (1 << i)) {
                    xorSum ^= nums[i];
                }
            }
            ans += xorSum;
        }
        
        return ans;
    }
};
