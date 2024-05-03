class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        int i = 0;
        int j = 0;
        int len1 = version1.size();
        int len2 = version2.size();
        int n1;
        int n2;

        while (i<len1 || j<len2)
        {
            n1 = 0;
            n2 = 0;

            while (i<len1 and version1[i]!='.')
            {
                n1 = n1*10 + (version1[i++]-'0');
            }
            while (j<len2 and version2[j]!='.')
            {
                n2 = n2*10 + (version2[j++]-'0');
            }

            if (n1>n2)
            {
                return 1;
            }
            else if (n1<n2)
            {
                return -1;
            }

            i++;
            j++;
        }

        return 0;
    }
};