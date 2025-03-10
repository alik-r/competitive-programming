class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool hasAllVowels(const vector<int>& cnt) {
        return cnt['a' - 'a'] > 0 && cnt['e' - 'a'] > 0
        && cnt['i' - 'a'] > 0 && cnt['o' - 'a'] > 0 && cnt['u' - 'a'] > 0;
    }

    long long countOfSubstringsWithAtleastKConsonants(string word, int k) {
        vector<int> cnt(26, 0);
        int consCnt = 0;
        bool allVowels = false;
        long long ans = 0;
        int l = 0;
        for (int r = 0; r < (int)word.size(); r++) {
            if (isVowel(word[r])) cnt[word[r] - 'a']++;
            else consCnt++;

            while (hasAllVowels(cnt) && consCnt >= k) {
                ans += word.size() - r;
                if (isVowel(word[l])) {
                    cnt[word[l] - 'a']--;
                } else {
                    consCnt--;
                }
                l++;
            }
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return countOfSubstringsWithAtleastKConsonants(word, k) -
         countOfSubstringsWithAtleastKConsonants(word, k + 1);
    }
};
