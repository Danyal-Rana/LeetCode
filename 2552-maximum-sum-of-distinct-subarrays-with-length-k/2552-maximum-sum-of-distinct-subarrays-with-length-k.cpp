class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        unordered_set<int> st;
        int n = nums.size();
        long long ans = 0;
        long long currSum = 0;

        int i = 0;
        int j = 0;

        while (j < n)
        {
            // checking: if nums[j] is already presant in window
            while (st.count(nums[j]))
            {
                currSum -= nums[i];
                st.erase(nums[i]);  
                i++;
            }

            currSum += nums[j];
            st.insert(nums[j]);

            if (j-i+1 == k)
            {
                ans = max(ans, currSum);
                currSum -= nums[i];
                st.erase(nums[i++]);
            }
            j++;
        }

        return ans; 
    }
};