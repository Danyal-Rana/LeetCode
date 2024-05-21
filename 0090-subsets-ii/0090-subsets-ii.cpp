class Solution {
public:
    
    bool alreadyExists(vector<vector<int>>& ans, vector<int>& output) 
    {
        for (const auto& vec : ans) 
        {
            if (vec == output) 
            {
                return true;
            }
        }
        return false;
    }
    
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &output, int i) 
    {
        if (i >= nums.size()) 
        {
            if (!alreadyExists(ans, output)) 
            {
                ans.push_back(output);
            }
            return;
        }
        
        // Include nums[i]
        output.push_back(nums[i]);
        helper(nums, ans, output, i + 1);
        
        // Exclude nums[i]
        output.pop_back();
        helper(nums, ans, output, i + 1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        
        // Sort the input to handle duplicates
        sort(nums.begin(), nums.end());
        
        helper(nums, ans, output, 0);
        return ans;
    }
};