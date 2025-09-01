class Solution {
    static double gain(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

    struct Compare {
        bool operator()(const pair<double, pair<int,int>>& a,
                        const pair<double, pair<int,int>>& b) const {
            return a.first < b.first;
        }
    };

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        typedef pair<double, pair<int,int>> Item;
        priority_queue<Item, vector<Item>, Compare> pq;

        for (size_t i = 0; i < classes.size(); i++) {
            int pass = classes[i][0], total = classes[i][1];
            pq.push(make_pair(gain(pass, total), make_pair(pass, total)));
        }

        while (extraStudents--) {
            Item top = pq.top(); 
            pq.pop();
            int pass = top.second.first + 1;
            int total = top.second.second + 1;
            pq.push(make_pair(gain(pass, total), make_pair(pass, total)));
        }

        double sum = 0.0;
        while (!pq.empty()) {
            sum += (double)pq.top().second.first / pq.top().second.second;
            pq.pop();
        }
        return sum / classes.size();
    }
};
