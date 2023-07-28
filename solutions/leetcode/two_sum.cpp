class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (mp.find(nums[i]) != mp.end()) {
                sol.push_back(mp[nums[i]]);
                sol.push_back(i);
                break;
            }
            mp[diff] = i;
        }

        return sol;
    }
};
