class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> line;
        int rem = grid[0][0] % x;
        for (vector<int> r : grid) {
            for (int num : r) {
                line.push_back(num);
                if (num % x != rem) return -1;
            }
        }

        sort(line.begin(), line.end());
        int median = line[line.size() / 2];

        int cnt = 0;
        for (int num : line) {
            cnt += abs(median - num) / x;
        }
        return cnt;
    }
};
