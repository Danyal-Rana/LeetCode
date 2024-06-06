class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
        map<int, int> myMap;

        for (int i=0; i<hand.size(); i++)
        {
            myMap[hand[i]]++;
        }

        for (auto i=myMap.begin(); i!=myMap.end(); )
        {
            if (i->second > 0)
            {
                for(int j=0; j<groupSize; j++)
                {
                    if (myMap[i->first + j] > 0)
                    {
                        myMap[i->first + j]--;
                    }
                    else
                    {
                        return false;
                    }
                }     
            }
            else
            {
                i++;
            }
        }

        return true;
    }
};