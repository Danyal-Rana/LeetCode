class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        string myStr = word1+word2;

        int i = 0;
        int j = 0;
        int k = 0;

        while (k<word1.size()+word2.size())
        {
            if (i<word1.size())
            {
                myStr[k++] = word1[i++];
            }

            if (j<word2.size())
            {
                myStr[k++] = word2[j++];
            }
        }

        return myStr;
    }
};