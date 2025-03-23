class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using ll = long long;

        vector<vector<pair<int, ll>>> adj(n);
        for (const vector<int>& r : roads) {
            ll w = r[2];
            adj[r[0]].push_back({r[1], w});
            adj[r[1]].push_back({r[0], w});
        }

        const int MOD = 1e9 + 7;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> minHeap; // (cost, node)
        vector<ll> minCost(n, numeric_limits<ll>::max());
        vector<int> pathCnt(n, 0);

        minCost[0] = 0;
        pathCnt[0] = 1;
        minHeap.push({0, 0});

        while (!minHeap.empty()) {
            auto p = minHeap.top();
            minHeap.pop();
            ll cost = p.first;
            int node = p.second;

            if(cost > minCost[node]) continue;

            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                ll nextCost = cost + neighbor.second;
                if (nextCost < minCost[nextNode]) {
                    minCost[nextNode] = nextCost;
                    pathCnt[nextNode] = pathCnt[node];
                    minHeap.push({nextCost, nextNode});
                } else if (nextCost == minCost[nextNode]) {
                    pathCnt[nextNode] = (pathCnt[nextNode] + pathCnt[node]) % MOD;
                }
            }
        }

        return pathCnt[n - 1];
    }
};
