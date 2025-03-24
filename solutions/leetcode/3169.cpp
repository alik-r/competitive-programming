class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), cmp);

        int pos = 0;
        for (int i = 1; i < meetings.size(); i++) {
            if (meetings[i][0] <= meetings[pos][1]) {
                meetings[pos][1] = max(meetings[pos][1], meetings[i][1]);
            } else {
                pos++;
                meetings[pos] = meetings[i];
            }
        }

        meetings.resize(pos + 1);

        int sum = meetings[0][0] - 1;
        for (int i = 1; i < (int)meetings.size(); i++) {
            sum += meetings[i][0] - meetings[i - 1][1] - 1;
        }
        sum += days - meetings[meetings.size() - 1][1];
        return sum;
    }
};
