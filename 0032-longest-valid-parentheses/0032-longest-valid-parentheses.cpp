class Solution
{
    public:
        int longestValidParentheses(string s)
        {
            stack<int> myStack;
            myStack.push (-1);
            int maxLen = 0;
            
            for (int i=0; i<s.size(); i++)
            {                
                if (s[i] == '(')
                {
                    myStack.push (i);
                }
                
                else
                {
                    myStack.pop();
                    
                    if (myStack.empty())
                    {
                        myStack.push (i);
                    }
                    else
                    {
                        int len = i - myStack.top();
                        maxLen = max (maxLen, len);
                    }
                }
            }
            return maxLen;
        }
};