class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lessers;
        vector<int> greaters;
        int equals = 0;
        for (int n : nums) {
            if (n == pivot) equals++;
            else if (n < pivot) lessers.push_back(n);
            else greaters.push_back(n);
        }
        vector<int> res;
        for (int n : lessers) res.push_back(n);
        for (int i = 0; i < equals; i++) res.push_back(pivot);
        for (int n : greaters) res.push_back(n);
        return res;
    }
};
