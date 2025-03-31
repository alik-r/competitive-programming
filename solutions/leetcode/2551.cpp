class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> splits(weights.size() - 1);
        for (int i = 0; i < weights.size() - 1; i++) {
            splits[i] = weights[i] + weights[i + 1];
        }

        sort(splits.begin(), splits.end());

        long long minScore = 0;
        long long maxScore = 0;
        for (int i = 0; i < k - 1; i++) {
            minScore += splits[i];
            maxScore += splits[splits.size() - 1 - i];
        }

        return maxScore - minScore;
    }
};
