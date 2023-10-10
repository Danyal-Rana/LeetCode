class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        string mergedStr;
        int i = 0;
        int j = 0;
        
        while (i < word1.size() && j < word2.size())
        {
            mergedStr += word1[i++];
            mergedStr += word2[j++];
        }
        
        while (i < word1.size())
        {
            mergedStr += word1[i++];
        }

        while (j < word2.size())
        {
            mergedStr += word2[j++];
        }
        
        return mergedStr;
    }
};
