class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0;
        int cnt = 0;
        int ans = k;
        for (int r = 0; r < (int)blocks.size(); r++) {
            if (blocks[r] == 'W') cnt++;
            if (r - l + 1 == k) {
                ans = min(ans, cnt);
                if (blocks[l++] == 'W') cnt--;
            }
        }
        return ans;
    }
};
