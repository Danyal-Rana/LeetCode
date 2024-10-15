class Solution {
public:
    long long minimumSteps(string s)
    {
        long long ans = 0;
        int oneCount = 0;

        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='1')
            {
                oneCount++;
            }
            else
            {
                ans += oneCount;
            }
        }

        return ans;
    }
};