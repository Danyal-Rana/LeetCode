class Solution {
public:
    int minChanges(string s)
    {
        int n = s.size();
        int currChar = s[0];
        int counter = 0;
        int ans = 0;

        for (int i=0; i<n; i++)
        {
            if (s[i]==currChar)
            {
                counter++;
                continue;
            }

            if (counter%2==0)
            {
                counter = 1;
            }
            else
            {
                ans += 1;
                counter = 0;
            }

            currChar = s[i];
        }

        return ans;
    }
};