class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        stack<int> myStack;
        vector<int> ans (temperatures.size());
        
        for (int i=temperatures.size()-1; i>=0; i--)
        {
            while (!myStack.empty() && temperatures[i] >= temperatures[myStack.top()])
            {
                myStack.pop();
            }
            
            if (myStack.empty())
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = myStack.top()-i;
            }
            
            myStack.push (i);
        }
        
        return ans;
    }
};