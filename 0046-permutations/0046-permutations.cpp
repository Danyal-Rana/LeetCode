class Solution {
public:
    
    void helper (vector<int> nums, vector<vector<int>> &v, int i)
    {
        if (i>=nums.size())
        {
            v.push_back (nums);
            return;
        }
        
        for (int j=i; j<nums.size(); j++)
        {
            swap (nums[i], nums[j]);
            helper (nums, v, i+1);
            
            swap (nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> v;
        
        helper (nums, v, 0);
        
        return v;
    }
};