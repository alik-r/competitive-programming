class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        size_t n = s.size();
        vector<string> ans;
        for (int i = 0; i < n; i += k) {
            string current = s.substr(i, k);
            if (current.size() < k) {
                current.append(k - current.size(), fill);
            }
            ans.push_back(current);
        }
        return ans;
    }
};
