class Solution {
public:
    double helper(double &x, int n)
    {
        if(n==0)
        {
            return 1;
        }
        if (n==1)
        {
            return x;
        }

        double half = helper(x, n/2);

        return half * half * (n%2==0 ? 1 : x); 
    }
    double myPow(double x, int n)
    {
        double ans = helper(x, n);
        if (n < 0)
        {
            ans = 1/ans;
        }

        return ans;
    }
};