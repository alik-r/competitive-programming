class Solution {
public:
    int countDigits(int n) {
        int numDigits = 0;
        while (n > 0) {
            n /= 10;
            numDigits++;
        }
        return numDigits;
    }

    bool isSymmetric(int n) {
        string s = to_string(n);
        int s1 = 0;
        int s2 = 0;
        for (int i = 0; i < s.size(); i++) {
            int digit = s[i] - '0';
            if (i < s.size() / 2) {
                s1 += digit;
            } else {
                s2 += digit;
            }
        }
        return s1 == s2;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            int digitCount = countDigits(i);
            if (digitCount % 2 == 1) {
                i = (int)pow(10, digitCount);
                continue;
            }

            if (isSymmetric(i)) {
                count++;
            }
        }
        return count;
    }
};
