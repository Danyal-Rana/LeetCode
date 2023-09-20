class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int count = 0;
        int minLength = INT_MAX;

        string myStr;

        for (int i=0; i<strs.size(); i++)
        {
            int len = strs[i].length();

            if (len < minLength)
            {
                minLength = len;
                myStr = strs[i];
            }
        }


        for (int i=0; i<minLength; i++)
        {
            for (int j=0; j<strs.size(); j++)
            {
                if (strs[j][i] != myStr[i])
                {
                    return myStr.substr (0, count);
                }
            }
            count++;
        }
        return myStr.substr (0, count);
    }
};