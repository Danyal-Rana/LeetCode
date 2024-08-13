class Solution {
public:

    void helper(vector<int> &candidates, int target, int idx, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (target < 0)
        {
            return;
        }
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (int i=idx; i<candidates.size(); i++)
        {
            if (i>idx and candidates[i]==candidates[i-1])
            {
                continue;
            }

            temp.push_back(candidates[i]); // do
            helper(candidates, target-candidates[i], i+1, ans, temp); // explore/backtrack
            temp.pop_back(); // undo
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, ans, temp);

        return ans;        
    }
};