class Solution {
public:
    int getSum(int a, int b)
    {
        int ans = max (a, b);
        int temp = min (a, b);
        
        if (ans>=0 && temp>=0)
        {
            for (int i=0; i<temp; i++)
            {
                ans++;
            }
        }
        else
        {
            for (int i=temp; i<0; i++)
            {
                ans--;
            }
        }
        
        return ans;
    }
};