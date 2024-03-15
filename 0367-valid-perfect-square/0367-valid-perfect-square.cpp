class Solution {
public:
    bool isPerfectSquare(int num)
    {
        int lastDigit = num%10;
        
        if (lastDigit==2 || lastDigit==3 || lastDigit==7 || lastDigit==8)
        {
            return false;
        }
        
        int left = 0;
        int right = num;
        
        while (left <= right)
        {
            long long int mid = left + (right-left)/2;
            long long int mySqr = mid*mid;
            
            if (mySqr==num)
            {
                return true;
            }
            else if (mySqr < num)
            {
                left = mid + 1;
            }
            else if (mySqr > num)
            {
                right = mid - 1;
            }
        }
        return false;
    }
};