class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> idx(26);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                idx[s[i] - 'a'].push(i);
                continue;
            }

            for (int j = 0; j < 26; j++) {
                if (!idx[j].empty()) {
                    s[idx[j].top()] = '*';
                    idx[j].pop();
                    break;
                }
            }
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
