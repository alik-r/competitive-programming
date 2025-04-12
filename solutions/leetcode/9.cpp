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

    bool isPalindrome(int x) {
        int reverseHalf = 0;
        int initDigitCnt = countDigits(x);
        while (countDigits(x) > initDigitCnt / 2) {
            reverseHalf = reverseHalf * 10 + x % 10;
            x /= 10;
        }

        if (initDigitCnt & 1) {
            reverseHalf /= 10;
        }

        return x == reverseHalf;
    }
};
