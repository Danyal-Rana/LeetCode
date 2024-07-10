class Solution {
public:
    int minOperations(vector<string>& logs)
    {
        stack<string> myStack;

        for (auto l : logs)
        {
            if (l == "./")
            {
                continue;
            }
            else if (l == "../")
            {
                if (!myStack.empty()) {
                    myStack.pop();
                }
            }
            else
            {
                myStack.push(l);
            }
        }

        return myStack.size();
    }
};