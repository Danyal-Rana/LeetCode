class Solution {
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        
        int secondLast = 1;
        int current = 2;
        
        for (int i=3; i<=n; i++)
        {
            int temp = current;
            current = current + secondLast;
            secondLast = temp;
        }
        
        return current;
    }
};