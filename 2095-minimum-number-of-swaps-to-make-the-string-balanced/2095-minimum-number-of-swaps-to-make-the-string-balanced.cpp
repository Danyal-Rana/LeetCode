class Solution {
public:
    int minSwaps(string s)
    {
        stack<char> myStack;

        for (auto &ch : s)
        {
            if (!myStack.empty() && myStack.top()=='[' && ch==']')
            {
                myStack.pop();
            }
            else if (ch=='[')
            {
                myStack.push(ch);
            }
        }

        return (myStack.size()+1)/2;
    }
};