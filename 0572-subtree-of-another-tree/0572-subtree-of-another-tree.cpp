class Solution {
public:
  bool isSameTree(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;

    if (root1->val != root2->val) return false;

    return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
  }

  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (subRoot == nullptr) return true;
    if (root == nullptr) return false;

    if (root->val == subRoot->val) {
      if (isSameTree(root, subRoot)) return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};
