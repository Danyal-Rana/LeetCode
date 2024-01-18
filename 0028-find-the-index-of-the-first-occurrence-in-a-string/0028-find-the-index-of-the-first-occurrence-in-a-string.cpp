class Solution {
public:
    int strStr(string haystack, string needle)
    {
        for (int i=0; i<haystack.size(); i++)
        {
            if (needle[0]==haystack[i])
            {
                int k = i;
                int m = i;
                int myCounter = 0;
                for (int j=0; j<needle.size(); j++)
                {
                    if (needle[j]==haystack[k++])
                        myCounter++;
                    else
                        break;
                }
                if (myCounter == needle.size())
                    return m;
            }
        }
        return -1;
    }
};