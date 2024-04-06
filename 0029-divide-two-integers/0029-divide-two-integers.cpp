class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        
        if (dividend == divisor)
            return 1;
        
        bool flag = (dividend>=0 and divisor>=0) || (dividend<=0 && divisor<=0) ? true : false;
        
        unsigned int ans = 0;
        
        unsigned int dd = abs(dividend);
        unsigned int dv = abs(divisor);
        
        while (dd >= dv)
        {
            int myCounter = 0;
            
            while (dd > (dv << myCounter+1) )
            {
                myCounter++;
            }
            
            ans += 1 << myCounter;
            dd -= dv << myCounter;
        }
        
        return flag ? ans : -ans;
    }
};