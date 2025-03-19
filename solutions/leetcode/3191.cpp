class Solution {
public:
    int flip(vector<int>& nums, int l, int r) {
        int nextZero = -1; 
        for (int i = l; i <= r; i++) {
            if (nums[i] == 1 && nextZero == -1) nextZero = i;
            nums[i] = nums[i] ^ 1;
        }
        return nextZero == -1 ? r : nextZero;
    }

    int minOperations(vector<int>& nums) {
        int l = 0;
        int r = 2;
        int cnt = 0;

        while (l < nums.size() && r < nums.size()) {
            if (nums[l] == 0) {
                l = flip(nums, l, r);
                r = l + 2;
                cnt++;
            } else {
                l++;
                r++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) return -1;
        }

        return cnt;
    }
};
