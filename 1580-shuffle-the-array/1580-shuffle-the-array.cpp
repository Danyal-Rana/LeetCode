class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n)
    {
        vector <int> myVector;

        for (int i=0; i<n; i++)
        {
            myVector.push_back(nums[i]);
            myVector.push_back(nums[i+n]);
        }
        return myVector;
    }
};