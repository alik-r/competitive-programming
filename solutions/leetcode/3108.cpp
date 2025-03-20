class UnionFind {
private:
    vector<int> parent;
    vector<int> size;
public:
    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionOp(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false;

        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind uf = UnionFind(n);

        for (vector<int> v : edges) {
            uf.unionOp(v[0], v[1]);
        }

        unordered_map<int, int> cost;
        for (vector<int> v : edges) {
            int root = uf.find(v[0]);
            if (cost.find(root) == cost.end()) {
                cost[root] = v[2];
            } else {
                cost[root] &= v[2];
            }
        }

        vector<int> ans(query.size());
        for (int i = 0; i < query.size(); i++) {
            int rootSrc = uf.find(query[i][0]);
            int rootDest = uf.find(query[i][1]);
            if (rootSrc != rootDest) ans[i] = -1;
            else ans[i] = cost[rootSrc];
        }
        return ans;
    }
};
