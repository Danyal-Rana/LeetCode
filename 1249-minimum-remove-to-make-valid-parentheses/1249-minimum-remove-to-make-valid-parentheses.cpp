class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> openingStack;

        string result = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                openingStack.push(i);
            }
            else if (s[i] == ')')
            {
                if (!openingStack.empty())
                {
                    openingStack.pop();
                }
                else
                {
                    s[i] = '*';
                }
            }
        }

        while (!openingStack.empty())
        {
            s[openingStack.top()] = '*';
            openingStack.pop();
        }

        for (char c : s)
        {
            if (c != '*')
            {
                result += c;
            }
        }

        return result;
    }
};