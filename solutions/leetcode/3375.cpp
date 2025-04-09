class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bool mp[101] {};
        int ops = 0;
        for (int num : nums) {
            if (num < k) return -1;

            if (num > k && !mp[num]) {
                mp[num] = true;
                ops++;
            }
        }
        return ops;
    }
};
