class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        vector<int> results;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) 
        {
            bool isConsecutive = true;
            for (int j = i; j < i + k - 1; j++) 
            {
                if (nums[j] + 1 != nums[j + 1]) 
                {
                    isConsecutive = false;
                    break;
                }
            }
            if (isConsecutive) 
            {
                results.push_back(*max_element(nums.begin() + i, nums.begin() + i + k));
            } 
            else 
            {
                results.push_back(-1);
            }
        }

        return results;
    }
};