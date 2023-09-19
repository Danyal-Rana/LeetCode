class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int sSize = s.size();
        int tSize = t.size();

        int i=0;
        int j=0;

        while (i<tSize && j<sSize)
        {
            if (s[j] == t[i])
            {
                j++;
            }
            i++;
        }
        return  j==sSize ? 1 : 0;
    }
};