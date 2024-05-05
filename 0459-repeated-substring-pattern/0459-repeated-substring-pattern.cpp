class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        
        for (int i=1; i<=n/2; i++)
        {
            if (n%i == 0)
            {
                string temp = "";
                int noOfRepititions = n/i;
                
                for (int j=0; j<noOfRepititions; j++)
                {
                    temp += s.substr(0, i);
                }
                
                if (s == temp)
                {
                    return true;
                }
            }
        }
        return false;
    }
};