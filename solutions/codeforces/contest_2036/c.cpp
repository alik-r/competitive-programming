#include "bits/stdc++.h"
using namespace std;

void setIO() {
    cin.tie(nullptr)->sync_with_stdio(false); 
}

bool check(const string &s, int idx) {
    if (idx >= 0 && idx <= (int)s.size() - 4) {
        return s[idx] == '1' && s[idx + 1] == '1' && s[idx + 2] == '0' && s[idx + 3] == '0';
    }
    return false;
}

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        int count1100 = 0;
        for (int i = 0; i <= n - 4; i++) {
            if (check(s, i)) count1100++;
        }

        int q; 
        cin >> q;
        while (q--) {
            int idx;
            char v;
            cin >> idx >> v;
            idx--;
            
            for (int j = idx - 3; j <= idx; j++) {
                if (check(s, j)) count1100--;
            }

            s[idx] = v;

            for (int j = idx - 3; j <= idx; j++) {
                if (check(s, j)) count1100++;
            }

            cout << (count1100 > 0 ? "YES" : "NO") << '\n';
        }
    }
}

