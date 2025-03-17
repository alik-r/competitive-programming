class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int cnt = 0;   
        vector<bool> flag(501, false);
        for (int i : nums) {
            if (flag[i]) {
                cnt++;
            }
            flag[i] = !flag[i];
        }    
        return cnt >= (int)nums.size() / 2;
    }
};
