class Solution {
public:
    string removeDuplicates(string s)
    {
        stack<char> myStack;
        
        string result;
        
        for (auto i : s)
        {
            if (!myStack.empty() && myStack.top()==i)
            {
                myStack.pop();
            }
            else
            {
                myStack.push (i);
            }
        }
        
        while (! myStack.empty())
        {
            result.insert (result.begin(), myStack.top());
            myStack.pop();
        }
        
        return result;
    }
};