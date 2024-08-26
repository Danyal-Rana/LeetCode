/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void helper(Node *&root, vector<int> &ans)
    {
        if (!root)
            return;

        for (auto child : root->children)
        {
            helper(child, ans);
            ans.push_back(child->val);
        }
    }

    vector<int> postorder(Node* root)
    {
        vector<int> ans;

        helper(root, ans);
        if (root)
        {
            ans.push_back(root->val);
        }

        return ans;
    }
};