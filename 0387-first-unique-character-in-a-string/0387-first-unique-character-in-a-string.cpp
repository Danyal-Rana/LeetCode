class Solution {
public:
    int firstUniqChar(string s)
    {
       
        for (int i=0; i<s.size(); i++)
        {
            int myCounter = 0;
            for (int j=0; j<s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    myCounter++;
                    if (myCounter > 1)
                    {
                        break;
                    }
                }
            }
            if (myCounter == 1)
            {
                return i;
            }
        }
        return -1;        
    }
};