class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int myLetters = 0;
        int myChecker = 0;

        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i] == ' ' && myChecker == 1)
            {
                break;
            }

            if (s[i] != ' ')
            {
                myLetters++;
                myChecker = 1;
            }
        }
        return myLetters;
    }
};