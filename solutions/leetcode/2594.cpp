class Solution {
public:
    using ll = long long;

    bool canBeRepairedInMinutes(vector<int>& ranks, int cars, ll time) {
        ll cnt = 0;
        for (int r : ranks) {
            cnt += (ll)floor(sqrt(time / r));
            if (cnt >= cars) return true;
        }
        return cnt >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());

        ll l = 1;
        ll r = ranks[ranks.size() - 1] * pow(cars, 2);
        while (l < r) {
            ll m = l + (r - l) / 2;
            if (canBeRepairedInMinutes(ranks, cars, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
