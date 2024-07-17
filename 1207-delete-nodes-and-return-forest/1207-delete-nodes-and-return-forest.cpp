class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<int,bool> mp;

    void solve(TreeNode* root,TreeNode* prev)
    {
         if(!root) return ;
         TreeNode* lft = root->left;
         TreeNode* rgt = root->right;
         if(mp.find(root->val)!=mp.end())
         {
             if(prev!=NULL)
             {
                 if(prev->left==root) prev->left = NULL;
                 else if(prev->right==root) prev->right = NULL;
             }
            root->left = NULL;
            root->right = NULL;
            if(lft && mp.find(lft->val)==mp.end()) ans.push_back(lft);
            if(rgt && mp.find(rgt->val)==mp.end()) ans.push_back(rgt);

            solve(lft,NULL);
            solve(rgt,NULL);
         }
         else
         {
             solve(lft,root);
             solve(rgt,root);
         }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
         for(auto x : to_delete) mp[x] = 1;
         if(mp.find(root->val)==mp.end()) ans.push_back(root);
         solve(root,NULL);
         return ans;
    }
};