class Solution {
public:
    int minLength(string s)
    {
        stack<char> myStack;

        for(int i = 0; i < s.size(); i++)
        {
            if (!myStack.empty() && ((myStack.top() == 'A' && s[i] == 'B') || (myStack.top() == 'C' && s[i] == 'D')))
            {
                myStack.pop();
            }
            else
            {
                myStack.push(s[i]);
            }
        }

        return myStack.size(); 
    }
};
