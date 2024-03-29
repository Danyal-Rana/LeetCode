class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        sort (strs.begin(), strs.end());
        
        int n = strs.size()-1;
        
        string myStr = "";
        
        for (int i=0; i<strs[0].size(); i++)
        {
            if (strs[0][i] == strs[n][i])
            {
                myStr += strs[0][i];
            }
            else
            {
                return myStr;
            }
        }
        
        return myStr;
    }
};