class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > (int)s.size()) return false;

        unordered_map<char, int> count;

        for (char ch : s) count[ch]++;

        int oddCount = 0;
        for (const auto& pair : count) {
            if (pair.second % 2 == 1) oddCount++;
        }

        return oddCount <= k;
    }
};
