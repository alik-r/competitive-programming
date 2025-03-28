class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int l = 0;
        int r = n * n + 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (m * w <= maxWeight) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l - 1;
    }
};
