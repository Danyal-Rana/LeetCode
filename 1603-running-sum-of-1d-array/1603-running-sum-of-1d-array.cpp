class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        int mySum = 0;

        vector <int> myVector;

        for (int i=0; i<nums.size(); i++)
        {
            mySum = mySum + nums[i];
            myVector.push_back(mySum);
        }

        return myVector;
    }
};