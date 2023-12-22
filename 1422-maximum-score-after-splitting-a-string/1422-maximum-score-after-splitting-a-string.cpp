class Solution {
public:
    int maxScore(string s)
    {
        int n = s.size();
        int maxi = 0;
        
        for (int i=1; i<n; i++)
        {
            int zero = 0;
            int one = 0;
            
            for (int j=i-1; j>=0; j--)
            {
                if (s[j]=='0')
                {
                    zero++;
                }
            }
            
            for (int j=i; j<n; j++)
            {
                if (s[j]=='1')
                {
                    one++;
                }
            }
            
            if (one+zero > maxi)
            {
                maxi = one+zero;
            }
        }
        return maxi;
        
    }
};