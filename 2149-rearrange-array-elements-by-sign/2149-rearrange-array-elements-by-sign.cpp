class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        vector <int> posVector;
        vector <int> negVector;

        vector <int> ansVector;

        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                posVector.push_back(nums[i]);
            }
            else if (nums[i] < 0 )
            {
                negVector.push_back (nums[i]);
            }
        }
    
        int p = 0;
        int n = 0;

        for (int i=0; i<nums.size(); i++)
        {
            if (i%2 == 0)
            {
                ansVector.push_back(posVector[p]);
                p++;
            }
            else if (i%2 != 0)
            {
                ansVector.push_back(negVector[n]);
                n++;
            }
        }
        return ansVector;        
    }
};