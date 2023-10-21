class Solution {
public:
    string removeStars(string s)
    {
        stack<char> myStack;
        string ans = "";

        for (int i=0; i<s.size(); i++)
        {
            if (s[i] == '*')
            {
                myStack.pop();
                ans.pop_back();
            }
            else
            {
                myStack.push (s[i]);
                ans.push_back (s[i]);
            }
        }
        
        return ans;
    }
};