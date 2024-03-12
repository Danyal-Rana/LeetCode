class Solution {
public:
    bool isPalindrome(int x)
    {
        int myNum = x;
        long int revNum = 0;

        if (x<0)
            return false;
        
        else
        {
            while (x>0)
            {
                int myDigit = x%10;
                x = x/10;
                revNum = (revNum * 10) + myDigit;
            }
        }

        if (revNum == myNum)
            return true;
        else
            return false;
    }
};