class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 1, maxSum = root->val, level = 1;
        queue<TreeNode*> levelNodes;
        levelNodes.push(root);

        while (!levelNodes.empty()) {
            int levelSum = 0;
            for (int i = levelNodes.size(); i > 0; i--) {
                TreeNode* front = levelNodes.front();
                levelNodes.pop();
                levelSum += front->val;
                if (front->left != nullptr) levelNodes.push(front->left);
                if (front->right != nullptr) levelNodes.push(front->right);
            }

            if (maxSum < levelSum) {
                ans = level;
                maxSum = levelSum;
            }

            level++;
        }

        return ans;
    }
};
