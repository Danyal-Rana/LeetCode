class Solution {
    string answer = "~";
public:     void recure(TreeNode* root,string s){
            if (!root) return;
            if (!root->left && !root->right){
                answer = min(answer,char(root->val+'a')+s);
            }
            recure(root->left,char(root->val+'a')+s);
            recure(root->right,char(root->val+'a')+s);
}
    string smallestFromLeaf(TreeNode* root) {
        recure(root,"");
        return answer;
    }
};