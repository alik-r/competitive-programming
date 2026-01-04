class Solution {
public:
    vector<int> sumMap;

    Solution() : sumMap(100001, -1) {}

    int sumOfDivisorsIfCountAboveFour(int num) {
        if (sumMap[num] != -1) return sumMap[num];

        int origNum = num;
        int sum = 1;
        int count = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                int e = 0;
                do {
                    e++;
                    num /= i;
                } while (num % i == 0);
                
                count *= e + 1;
                if (count > 4) return 0;

                int loopSum = 0, term = 1;
                do {
                    loopSum += term;
                    term *= i;
                } while (e-- > 0);
                sum *= loopSum;
            }
        }

        if (num > 1) {
            count *= 2;
            sum *= (num + 1);
        }

        if (count != 4) return 0;

        sumMap[origNum] = sum;
        return sum;
    }

    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += sumOfDivisorsIfCountAboveFour(num);
        }
        return sum;
    }
};
