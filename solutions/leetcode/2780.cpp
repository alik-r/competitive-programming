class Solution {
public:
    bool validSplit(const vector<int>& nums, const vector<int>& prefix, int total, int l, int r) {
        if (l == 0) {
            return prefix[r - 1] * 2 > r;
        }
        return (total - prefix[l - 1]) * 2 > (r - l); 
    }

    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        int x;
        int total;
        for (const auto& pair : freq) {
            if (pair.second * 2 > nums.size()) {
                x = pair.first;
                total = pair.second;
                break;
            }
        }

        vector<int> prefix(nums.size(), 0);
        prefix[0] = (nums[0] == x) ? 1 : 0;
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + ((nums[i] == x) ? 1 : 0);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (validSplit(nums, prefix, total, 0, i + 1) 
                && validSplit(nums, prefix, total, i + 1, nums.size())) {
                return i;
            }
        }

        return -1;
    }
};
