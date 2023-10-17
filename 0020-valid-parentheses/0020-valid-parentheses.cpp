class Solution {
public:
    bool isValid(string s)
    {
        stack <char> myStack;

        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                myStack.push (s[i]);
            }

            else
            {
                if (myStack.empty())
                {
                    return false;
                }
                else
                {
                    if (myStack.top()=='(' && s[i]==')')
                    {
                        myStack.pop();
                    }
                    else if (myStack.top()=='{' && s[i]=='}')
                    {
                        myStack.pop();
                    }
                    else if (myStack.top()=='[' && s[i]==']')
                    {
                        myStack.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        } 
        if (myStack.empty())
        {
            return true;
        }       
        return false;
    }
};