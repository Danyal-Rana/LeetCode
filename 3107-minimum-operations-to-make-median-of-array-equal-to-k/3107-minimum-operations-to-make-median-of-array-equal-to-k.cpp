class Solution
{
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {
        if (nums.empty())
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), mid = n / 2;
        
        long long operations = 0;
        
        if (n == 1)
            return abs((long long)nums[0] - k);
        
        if (nums[mid] == k)
            return 0;
        else if (nums[mid] < k)
        {
            for (int i = mid; i < n && nums[i] < k; ++i)
                operations += k - nums[i];
        }
        else
        {
            for (int i = mid; i >= 0 && nums[i] > k; --i)
                operations += nums[i] - k;
        }
        bool allEqual = true;
        for (int i = 0; i < n; ++i)
            if (nums[i] != k)
            {
                allEqual = false;
                break;
            }
        if (allEqual)
            return 0;
        return operations;
    }
};