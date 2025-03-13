class Solution {
public:
    bool firstKWillZero(const vector<int>& nums, const vector<vector<int>>& queries, int k) {
        using ll = long long;
        int n = (int)nums.size();
        int q = (int)queries.size();
        vector<ll> diff(n + 1, 0);
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] += val;
            if (r + 1 < n) diff[r + 1] -= val;
        }
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (sum < nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int q = (int)queries.size();
        int l = 0;
        int r = q + 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (firstKWillZero(nums, queries, m)) r = m;
            else l = m + 1;
        }
        if (l > q) return -1;
        return l;
    }
};
