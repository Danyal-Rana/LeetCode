class Solution {
public:
    string reversePrefix(string word, char ch)
    {
        stack<char> myStack;
        int myIndex = -1;
        
        for (int i=0; i<word.size(); i++)
        {
            myStack.push(word[i]);
            if (myStack.top() == ch)
            {
                myIndex = i;
                break;
            }
        }
        
        for(int i=0; myIndex!=-1 and i<=myIndex; i++)
        {
            word[i] = myStack.top();
            myStack.pop();
        }
        
        return word;
    }
};