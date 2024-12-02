class Solution {
public:
    int climbStairs(int n)
    {
        int preOfPre = 1;
        int pre = 1;

        for (int i=2; i<=n; i++)
        {
            int x = pre+preOfPre;
            preOfPre = pre;
            pre = x;
        }

        return pre;
    }
};