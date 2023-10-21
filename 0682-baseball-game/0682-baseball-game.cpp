class Solution {
public:
    int calPoints(vector<string>& operations)
    {
        stack<int> myStack;

        int x = 0;

        for (int i=0; i<operations.size(); i++)
        {
            if (operations[i] == "+")
            {
                int num1 = myStack.top();
                myStack.pop();
                int num2 = myStack.top();
                myStack.pop();

                myStack.push (num2);
                myStack.push (num1);
                myStack.push (num1+num2);
            }

            else if (operations[i] == "D")
            {
                int num = myStack.top();
                myStack.push (num*2);
            }

            else if (operations[i] == "C")
            {
                myStack.pop ();
            }

            else
            {
                int a = stoi (operations[i]);
                myStack.push (a);
            }
        }
        
        while (! myStack.empty())
        {
            x += myStack.top();
            myStack.pop();
        }
        return x;
    }
};