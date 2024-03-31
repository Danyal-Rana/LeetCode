class Solution {
public:
    double myPow(double x, int n)
    {
        double myResult = 1;
        
        int m = abs(n);
        
        while (m > 0)
        {
            if (m%2 != 0)
            {
                myResult *= x;
            }
            
            x *= x;
            m /= 2;
        }
        
        return (n>0) ? myResult : 1/myResult;
    }
};