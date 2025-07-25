class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<bool> seen(101, false);
        int sum = 0;
        int maxNum = nums[0];
        for (int num : nums) {
            maxNum = max(maxNum, num);
            if (num < 0 || seen[num]) continue;
            sum += num;
            seen[num] = true;
        }
        return maxNum < 0 ? maxNum : sum;
    }
};
