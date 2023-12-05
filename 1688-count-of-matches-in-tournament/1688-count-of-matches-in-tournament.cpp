class Solution {
public:
    int numberOfMatches(int n)
    {
        int m = 0;
        int t = n;
        
        while (t != 1)
        {
            m += t/2;
            
            if (t%2 == 0)
            {
                t = t/2;
            }
            else
            {
                t = (t/2)+1;
            }
        }
        
        return m;
    }
};