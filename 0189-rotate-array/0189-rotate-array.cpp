class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int mySize = nums.size();
        vector<int> myVector (mySize);
        
        for (int i=0; i<mySize; i++)
        {
            myVector[(i+k)%mySize] = nums[i];
        }
        nums = myVector;
    }
};