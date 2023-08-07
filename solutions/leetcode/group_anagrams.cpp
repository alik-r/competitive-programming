class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < (int)strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());

            if (mp.find(sorted) != mp.end()) {
                mp[sorted].push_back(strs[i]);
            } else {
                vector<string> vec = {strs[i]};
                mp[sorted] = vec;
            }
        }

        vector<vector<string>> ans;
        for (const auto& item : mp) {
            ans.push_back(item.second);
        }
        return ans;
    }
};
