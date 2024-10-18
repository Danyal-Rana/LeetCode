class Solution {
public:

    int countSubSets(int idx, vector<int>& nums, int currOR, int maxOR)
    {
        if (idx == nums.size())
        {
            if (currOR == maxOR)
            {
                return 1;
            }
            return 0;
        }

        int takeEle = countSubSets(idx+1, nums, currOR | nums[idx], maxOR);
        int notTakeEle = countSubSets(idx+1, nums, currOR, maxOR);

        return takeEle + notTakeEle;
    }

    int countMaxOrSubsets(vector<int>& nums)
    {
        int maxOR = 0;

        for (auto &num : nums)
        {
            maxOR |= num;
        }

        int currOR = 0;
        return countSubSets(0, nums, currOR, maxOR);
    }
};