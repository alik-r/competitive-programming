class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        for (int i = 0; i < s.size(); i++) {
            last[s[i]] = i;
        }

        vector<int> ans;
        int l = 0;
        int r = 0;
        for (int i = 0; i < s.size(); i++) {
            r = max(r, last[s[i]]);
            if (i == r) {
                ans.push_back(r - l + 1);
                l = i + 1;
            }
        }

        return ans;
    }
};
