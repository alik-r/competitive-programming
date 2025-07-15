class Solution {
public:
    bool isAlphanum(char c) {
        return isalnum(static_cast<unsigned char>(c));
    }

    bool isVowel(char c) {
        char lc = tolower(static_cast<unsigned char>(c));
        switch (lc) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                return true;
        }
        return false;
    }

    bool isConsonant(char c) {
        char lc = tolower(static_cast<unsigned char>(c));
        if (isalpha(static_cast<unsigned char>(lc))) {
            switch (lc) {
                case 'a': case 'e': case 'i': case 'o': case 'u':
                return false;
            }  
            return true;
        }
        return false;
    }

    bool isValid(string word) {
        if (word.size() < 3) return false;
        bool containsVowel = false;
        bool containsConsonant = false;

        for (char c : word) {
            if (!isAlphanum(c)) return false;
            if (isVowel(c)) containsVowel = true;
            if (isConsonant(c)) containsConsonant = true;
        }

        return containsVowel && containsConsonant;
    }
};
