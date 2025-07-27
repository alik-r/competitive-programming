class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m + 1] > nums[m]) l = m + 1;
            else r = m;
        }
        return l;
    }
};
