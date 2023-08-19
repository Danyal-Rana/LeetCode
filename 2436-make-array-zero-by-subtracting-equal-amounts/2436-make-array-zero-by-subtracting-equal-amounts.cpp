class Solution {
public:
    int minElement (vector<int> myArray)
    {
        int minEle = INT_MAX;

        for (int i : myArray)
        {
            if (i!=0 && i<minEle)
            {
                minEle = i;
            }
        }
        return minEle;
    }

    int minimumOperations(vector<int>& nums)
    {
        int myCounter = 0;

        while (true)
        {
            int minE = minElement(nums);

            if (minE == INT_MAX)
            {
                break;
            }

            for (int i=0; i<nums.size(); i++)
            {
                if (nums[i] != 0)
                {
                    nums[i] = nums[i]-minE;
                }
            }

            myCounter++;
        }

        return myCounter;                
    }
};