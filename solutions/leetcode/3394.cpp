class Solution {
public:
    static int nonOverlappingCount(const vector<vector<int>>& v) {
        int cnt = 0;
        int lastEnd = -1;
        for (const vector<int>& i : v) {
            if (lastEnd <= i[0]) {
                cnt++;
            }
            lastEnd = max(lastEnd, i[1]);
        }
        return cnt;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x;
        vector<vector<int>> y;
        for (vector<int>& r : rectangles) {
            x.push_back({r[0], r[2]});
            y.push_back({r[1], r[3]});
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        return max(nonOverlappingCount(x), nonOverlappingCount(y)) >= 3;
    }
};
