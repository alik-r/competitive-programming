class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int current = 1;
        
        for (int i = 1; i <= n; i++) {
            ans.push_back(current);
            
            if (current * 10 <= n) {
                current *= 10;
            } else {
                while (current % 10 == 9 || current + 1 > n) {
                    current /= 10;
                }
                current++;
            }
        }

        return ans;
    }
};
