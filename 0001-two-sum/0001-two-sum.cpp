class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector <int> myVector;
        for (int i=0; i<nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                if (nums[i]+nums[j] == target)
                {
                    myVector.push_back(i);
                    myVector.push_back(j);
                    break;
                }
            }
        }
        return myVector;        
    }
};