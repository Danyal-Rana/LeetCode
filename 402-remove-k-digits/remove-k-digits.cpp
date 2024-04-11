class Solution {
public:
    string removeKdigits(string num, int k)
    {
        stack<char> myStack;
        
        int n = num.size();
        
        for (char i : num)
        {
            while (!myStack.empty() && k>0 && i<myStack.top())
            {
                myStack.pop();
                k--;
            }
            if (!myStack.empty() || i!='0')
            {
                myStack.push (i);
            }
        }
        
        while (!myStack.empty() && k>0)
        {
            myStack.pop();
            k--;
        }
        if (myStack.empty())
        {
            return "0";
        }
        
        while (!myStack.empty())
        {
            num[n-1] = myStack.top();
            myStack.pop();
            n -= 1;
        }
        
        return num.substr(n);
    }
};