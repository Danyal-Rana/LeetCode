class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> openBrac;
        stack<int> asterisk;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                openBrac.push(i);
            }
            else if (s[i] == '*')
            {
                asterisk.push(i);
            }
            else
            {
                if (!openBrac.empty())
                {
                    openBrac.pop();
                }
                else if (!asterisk.empty())
                {
                    asterisk.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        while (!openBrac.empty() && !asterisk.empty())
        {
            if (openBrac.top() < asterisk.top())
            {
                openBrac.pop();
                asterisk.pop();
            }
            else
            {
                break;
            }
        }

        return openBrac.empty();
    }
};