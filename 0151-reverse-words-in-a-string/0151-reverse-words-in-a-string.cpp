class Solution {
public:
    string reverseWords(string s)
    {
        string myStr = "";
        string sTemp;

        int i = 0;
        int sSize = s.size();

        while (i < sSize)
        {
            while (i<sSize && s[i] == ' ')
            {
                i++;
            }
            while (i<sSize && s[i] != ' ')
            {
                sTemp.push_back(s[i]);
                i++;
            }

            if (!sTemp.empty())
            {
                if (!myStr.empty())
                {
                    myStr = " " + myStr;
                }
                myStr = sTemp + myStr;
                sTemp.clear();
            }
        }
        return myStr;
    }
};