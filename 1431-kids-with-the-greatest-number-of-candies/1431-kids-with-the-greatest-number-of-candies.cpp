class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        vector <bool> myVector;

        for (int i=0; i<candies.size(); i++)
        {
            bool myChecker = true;
            int j=0;
            while (j < candies.size())
            {
                if (candies[i]+extraCandies < candies[j])
                {
                    myChecker = false;
                    break;
                }
                j++;
            }
            myVector.push_back(myChecker);
        }
        return myVector;
    }
};