class Solution {
public:
    double myPow(double x, int n)
    {
        long int m = (long int)n;
        static double ans = 1;
        if (m == 0)
        {
            return 1;
        }

        if (m>0)
        {
            if (m%2 == 0)
            {
                ans = myPow(x*x, m/2);
            }
            else
            {
                ans = x*(myPow(x*x, (m-1)/2));
            }
        }

        else if (m<0)
        {
            m = -m;
            if (m%2 == 0)
            {
                ans = 1 / myPow(x*x, m/2);
            }
            else
            {
                ans = 1 / (x*myPow(x*x, (m-1)/2));
            }
        }
        return ans;
    }
};