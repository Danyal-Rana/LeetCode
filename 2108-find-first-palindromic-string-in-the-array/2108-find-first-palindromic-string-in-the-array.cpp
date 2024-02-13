class Solution {
public:
    
    bool helper (string s)
    {
        for (int i=0, j=s.size()-1; i<s.size(); i++,j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words)
    {
        string ans = "";
        
        for (int i=0; i<words.size(); i++)
        {
            if (helper(words[i]))
            {
                ans = words[i];
                break;
            }
        }
        
        return ans;
    }
};