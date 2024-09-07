class Solution {
public:
    TreeNode *findNode (TreeNode *root, int x)
    {
        if (root == nullptr) return nullptr;

        if (root->val == x) 
        {
            return root;
        }
        else if (root->val > x)
        {
            return findNode(root->left, x);
        }
        else if (root->val < x)
        {
            return findNode(root->right, x);
        }
        return nullptr;
    }

    bool findPath(TreeNode *root, ListNode *head)
    {
        if (!head) return true; 
        if (!root) return false;

        if (root->val == head->val) 
        {
            return findPath(root->left, head->next) || findPath(root->right, head->next);
        }

        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if (!root) return false;

        if (findPath(root, head)) 
        {
            return true;
        }

        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};