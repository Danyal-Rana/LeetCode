class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        sort(s1.begin(), s1.end());

        for (int i=0; i<=m-n; i++)
        {
            string curSubStr = s2.substr(i, n);
            sort (curSubStr.begin(), curSubStr.end());

            if (s1 == curSubStr)
            {
                return true;
            }
        }

        return false;
    }
};