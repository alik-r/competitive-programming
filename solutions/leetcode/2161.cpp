class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = (int)nums.size();
        int l = 0;
        int l2 = l;
        int r = n - 1;
        int r2 = r;
        vector<int> ans(n, pivot);

        while (l < n) {
            if (nums[l] < pivot) ans[l2++] = nums[l];
            if (nums[r] > pivot) ans[r2--] = nums[r];
            l++, r--;
        }

        return ans;
    }
};
