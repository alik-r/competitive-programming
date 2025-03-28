class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<pair<int, int>> qs; // (query val, orig idx)
        for (int i = 0; i < queries.size(); i++) {
            qs.push_back({queries[i], i});
        }
        sort(qs.begin(), qs.end());

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minHeap;
        minHeap.push({grid[0][0], 0, 0});

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[0][0] = true;

        vector<int> ans(qs.size(), 0);
        int points = 0;

        for (const pair<int, int>& p : qs) {
            int limit = p.first;
            int idx = p.second;
            while (!minHeap.empty() && minHeap.top()[0] < limit) {
                array<int, 3> arr = minHeap.top();
                minHeap.pop();
                int val = arr[0];
                int r = arr[1];
                int c = arr[2];
                points++;
                vector<pair<int, int>> neighbors = {
                    {r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}
                };
                for (const pair<int, int>& nei : neighbors) {
                    int nr = nei.first;
                    int nc = nei.second;
                    if (0 <= nr && nr < rows && 0 <= nc && nc < cols && !visited[nr][nc]) {
                        minHeap.push({grid[nr][nc], nr, nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            ans[idx] = points;
        }
        return ans;
    }
};
