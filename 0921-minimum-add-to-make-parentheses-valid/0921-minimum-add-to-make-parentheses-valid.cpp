class Solution {
public:
    int minAddToMakeValid(string s)
    {
        stack<char> myStack;
        
        for (char c : s)
        {
            if (!myStack.empty() && (myStack.top()=='(' && c==')'))
            {
                myStack.pop();
            }
            else
            {
                myStack.push (c);
            }
        }
        
        return myStack.size();
    }
};