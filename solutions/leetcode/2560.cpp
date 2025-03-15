class Solution {
public:
    bool isValidCap(const vector<int>& nums, int k, int cap) {
        int i = 0;
        int cnt = 0;
        while (i < nums.size()) {
            if (nums[i] <= cap) {
                i += 2;
                cnt++;
            } else {
                i++;
            }

            if (cnt == k) break;
        }
        return cnt == k;
    }

    int minCapability(vector<int>& nums, int k) {
        int l = 2e9;
        int r = 0;
        for (int n : nums) {
            l = min(l, n);
            r = max(r, n);
        }

        int ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (isValidCap(nums, k, m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
