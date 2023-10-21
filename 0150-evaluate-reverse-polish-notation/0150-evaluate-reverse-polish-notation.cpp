class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> myStack;

        for (int i=0; i<tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                int num1 = myStack.top();
                myStack.pop();
                int num2 = myStack.top();
                myStack.pop();

                myStack.push (num1+num2);
            }

            else if (tokens[i] == "-")
            {
                int num1 = myStack.top();
                myStack.pop();
                int num2 = myStack.top();
                myStack.pop();

                myStack.push (num2-num1);
            }

            else if (tokens[i] == "*")
            {
                int num1 = myStack.top();
                myStack.pop();
                int num2 = myStack.top();
                myStack.pop();

                myStack.push (num1*num2);
            }

            else if (tokens[i] == "/")
            {
                int num1 = myStack.top();
                myStack.pop();
                int num2 = myStack.top();
                myStack.pop();

                myStack.push (num2/num1);
            }

            else
            {
                int a = stoi (tokens[i]);
                myStack.push (a);
            }
        }
        return myStack.top();
    }
};