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
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        if (nums.size() == 0)
            return NULL;

        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums, int beg, int end)
    {

        if (beg > end)
            return NULL;

        if (beg == end)
            return new TreeNode(nums[beg]);

        int mid = (beg + end) / 2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left = sortedArrayToBST(nums, beg, mid - 1);

        root->right = sortedArrayToBST(nums, mid + 1, end);

        return root;
    }
};