class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int left = 0;
        int right = 1;
        while (right < nums.size() - 1) {
            if (nums[left] == nums[right] || nums[right] == nums[right + 1]) {
                right++;
                continue;
            }

            if ((nums[left] < nums[right]) ^ (nums[right] < nums[right + 1])) {
                count++;
            }

            left = right;
            right++;
        }
        return count;
    }
};
