class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int sSize = s.size();
        int tSize = t.size();

        int i=0, j=0;

        while (i<sSize && j<tSize)
        {
            if (s[i] == t[j])
            {
                i++;
            }
            j++;
        }

        return i==sSize ? true : false; 
    }
};