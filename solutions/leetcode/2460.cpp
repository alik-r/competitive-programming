class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                if (nums[i] == 0) continue;
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == 0) {
                int idx = i + 1;
                while (nums[i] == 0 && idx < n) swap(nums[i], nums[idx++]);
            }
        }

        return nums;
    }
};
