class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& output)
    {
        if(i >= nums.size()){
            ans.push_back(output);
            return;
        }


        output.push_back(nums[i]);
        solve(nums, i+1, ans, output);
        output.pop_back();

        solve(nums, i+1, ans, output);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int i = 0;
        solve(nums, i, ans, output);
        return ans;
    }
};