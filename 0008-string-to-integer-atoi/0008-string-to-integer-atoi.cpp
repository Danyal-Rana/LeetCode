class Solution {
public:
    int myAtoi(string s)
    {
        int sign = 1;
        int result = 0;
        int i = 0;
        int n = s.length();

        while (i < n && s[i] == ' ') 
        {
            i++;
        }

        if (i < n && s[i] == '+') 
        {
            sign = 1;
            i++;
        } 
        else if (i < n && s[i] == '-') 
        {
            sign = -1;
            i++;
        }

        while (i < n && '0' <= s[i] && s[i] <= '9') 
        {
            if (result > numeric_limits<int>::max() / 10 ||
                (result == numeric_limits<int>::max() / 10 && (s[i] - '0') > numeric_limits<int>::max() % 10)) 
            {
                return result = (sign == 1 ? numeric_limits<int>::max() : numeric_limits<int>::min());
            }
            result *= 10;
            result += (s[i] - '0');
            i++;
        }

        return result * sign;
    }
};