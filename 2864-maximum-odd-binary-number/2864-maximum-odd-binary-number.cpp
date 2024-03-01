class Solution {
public:
    string maximumOddBinaryNumber(string s)
    {
        int one = 0;
        int zero = 0;
        
        for (auto i : s)
        {
            if (i == '1')
                one++;
            else
                zero++;
        }
        
        one -= 1;
        int i = 0;
        
        while (i < s.size())
        {
            if (one != 0)
            {
                s[i] = '1';
                one--;
            }
            else if (zero != 0)
            {
                s[i] = '0';
                zero--;
            }
            else
            {
                s[i] = '1';
            }
            i++;
        }
        return s;
    }
};