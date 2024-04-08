class Solution {
public:
    string getSmallestString(string s, int k)
    {
        if (k==0)
        {
            return s;
        }

        for (char &c : s)
        {
            int left = c - 'a';
            int right = 26-left;

            int minDif = min(left, right);

            if (minDif <= k)
            {
                k = k-minDif;
                c = 'a';
            }
            else
            {
                c = c-k;
                break;
            }
        }
        return s;
    }
};