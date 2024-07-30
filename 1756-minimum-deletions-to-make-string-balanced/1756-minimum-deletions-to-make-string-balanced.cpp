class Solution {
public:
    int minimumDeletions(string s)
    {
        int aCountRight = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i] == 'a')
            {
                aCountRight++;
            }
        }

        int bCountRight = 0;
        int ans = INT_MAX;

        for (int i=0; i<s.size(); i++)
        {
            if (s[i] == 'a')
            {
                aCountRight--;
            }
            ans = min(ans, aCountRight+bCountRight);

            if (s[i] == 'b')
            {
                bCountRight++;
            }
        }

        return ans;
    }
};