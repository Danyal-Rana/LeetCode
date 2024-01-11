class Solution {
public:
    int maxAncestorDiff(TreeNode* root) 
    {
        if (!root) 
        {
            return 0;
        }

        int ans = 0;
        dfs(root, root->val, root->val, ans);
        return ans;
    }

private:
    void dfs(TreeNode* node, int currMin, int currMax, int& ans) 
    {
        if (!node) 
        {
            return;
        }

        ans = max(ans, abs(currMax - node->val));
        ans = max(ans, abs(currMin - node->val));

        currMin = min(currMin, node->val);
        currMax = max(currMax, node->val);

        dfs(node->left, currMin, currMax, ans);
        dfs(node->right, currMin, currMax, ans);
    }
};
