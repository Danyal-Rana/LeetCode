#include <string>
using namespace std;

class Solution {
public:
    string makeGood(string s)
    {
        if (s.size() <= 1) 
        {
            return s;
        }

        int i = 1;

        while (i < s.size())
        {
            if (tolower(s[i]) == tolower(s[i - 1]) && s[i] != s[i - 1]) 
            {
                s.erase(i - 1, 2);

                if (i > 1)
                {
                    i--;
                }
            }
            else
            {
                i++;
            }
        }

        return s;
    }
};
