class Solution {
public:
    bool isPalindrome(string s)
    {
        string revString;
        for (int i=s.length() - 1; i>=0; i--)
        {
            if (isalnum(s[i]))
            {
                s[i] = tolower(s[i]);
                revString.push_back(s[i]);
            }
            else
            {
                s.erase(i, 1);
            }
        }

        if (s == revString)
            return true;
        else
            return false;
    }
};