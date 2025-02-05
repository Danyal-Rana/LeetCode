class Solution {
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int firstIndDif = 0;
        int secondIndDif = 0;
        int numDiffs = 0;

        for(int i=0; i<s1.size(); i++)
        {
            if (s1[i]!=s2[i])
            {
                numDiffs++;

                if (numDiffs>2)
                {
                    return false;
                }
                else if (numDiffs==1)
                {
                    firstIndDif = i;
                }
                else
                {
                    secondIndDif = i;
                }
            }
        }

        return s1[firstIndDif]==s2[secondIndDif] && s1[secondIndDif]==s2[firstIndDif];
    }
};