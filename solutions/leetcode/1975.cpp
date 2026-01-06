using ll = long long;

class Solution {
public:    
    ll maxMatrixSum(vector<vector<int>>& matrix) {
        int countNeg = 0;
        ll sum = 0;
        int n = matrix[0].size();
        int absMin = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int current = matrix[i][j];
                countNeg += (current < 0) ? 1 : 0;
                sum += abs(current);
                absMin = min(absMin, abs(current));
            }
        }
        if (countNeg % 2 == 1) sum -= 2 * absMin;
        return sum;
    }
};
