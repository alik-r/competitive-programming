class Solution {
public:
    string rev(string s) {
        string s2(s);
        reverse(s2.begin(), s2.end());
        return s2;
    }

    int longestPalindrome(vector<string>& words) {
        unordered_map<string, size_t> count;
        for (string w : words) count[w]++;

        size_t wordCnt = 0;
        bool hasCenter = false;
        unordered_set<string> visited;

        for (auto const& p : count) {
            string k1 = p.first;
            if (visited.count(k1) > 0) continue;

            string k2 = rev(k1);
            if (k1 == k2) {
                wordCnt += (count[k1] / 2) * 2;
                if (count[k1] % 2 == 1) hasCenter = true;
            } else if (count.count(k2)) {
                wordCnt += 2 * min(count[k1], count[k2]);
                visited.insert(k2);
            }

            visited.insert(k1);
        }
        
        if (hasCenter) wordCnt++;
        return wordCnt * 2;
    }
};
