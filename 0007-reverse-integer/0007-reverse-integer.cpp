class Solution {
public:
    int reverse(int x) {
        long revNum = 0;

        while (x != 0)
        {
            int digit = x % 10;

            x = x / 10;

            revNum = revNum * 10 + digit;

            if (revNum > INT_MAX || revNum < INT_MIN)
            {
                return 0;
            }
            
        }

        return revNum;
    }
};