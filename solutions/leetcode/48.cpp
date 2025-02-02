class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int temp;
        for (int layer = 0; layer < floor(n / 2); layer++) {
            for (int i = layer; i < n - layer - 1; i++) {
                temp = matrix[layer][i]; // top
                matrix[layer][i] = matrix[n - 1 - i][layer]; // top = left
                matrix[n - 1 - i][layer] = matrix[n - 1 - layer][n - 1 - i]; // left = bottom
                matrix[n - 1 - layer][n - 1 - i] = matrix[i][n - 1 - layer]; // bottom = right
                matrix[i][n - 1 - layer] = temp; // right = top
            }
        }
    }
};
