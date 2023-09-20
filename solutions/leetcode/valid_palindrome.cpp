class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 1) {
            return true;
        }

        // Convert uppercase letters into lowercase letters
        for (char &c : s) {
            c = tolower(c);
        }

        // Remove all non-alphanumeric characters
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c);
        }), s.end());

        for (int i = 0, j = (int)s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }

        return true;
    }
};
