class Solution {
public:
    int takeCharacters(string s, int k)
    {
        int n = s.size();
        int a = 0;
        int b = 0;
        int c = 0;

        for (char &ch : s)
        {
            if (ch == 'a')
                a++;
            else if (ch == 'b')
                b++;
            else
                c++;
        }

        if (a<k || b<k || c<k)
            return -1;
        
        int notToDel = 0;
        int i = 0;
        int j = 0;

        while (j<n)
        {
            if (s[j]=='a')
                a--;
            else if (s[j]=='b')
                b--;
            else
                c--;

            // if deletion count of any char becomes < k, than shrink the window to bring them back
            while (i<=j && (a<k || b<k || c<k))
            {
                if (s[i] == 'a')
                    a++;
                else if (s[i] == 'b')
                    b++;
                else
                    c++;

                i++;
            }

            notToDel = max(notToDel, j-i+1);
            j++;
        }

        return n-notToDel;
    }
};