/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth <= 0)
            return nullptr;
        TreeNode* returnNode;
        if (depth == 1)
        {
            returnNode = new TreeNode(val, root, nullptr);
        }
        else if (depth == 2)
        {
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
            returnNode = root;
        }
        else
        {
            // Depth is > 2 at this point
            // Traversal possible only if 1 non-null child node exists
            if (root->left != nullptr)
			{
				addOneRow(root->left, val, depth-1);
			}
			if (root->right != nullptr)
			{
				addOneRow(root->right, val, depth-1);
			}
            returnNode = root;
        }
        return returnNode;
    }
};