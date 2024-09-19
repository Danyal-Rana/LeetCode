class Solution {
public:

    vector<int> helper(string s)
    {
        vector<int> ans;

        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='+' || s[i]=='-' || s[i]=='*')
            {
                vector<int> leftAns = helper(s.substr(0, i));
                vector<int> rightAns = helper(s.substr(i+1));

                for (int &x : leftAns)
                {
                    for (int &y : rightAns)
                    {
                        if (s[i]=='+')
                        {
                            ans.push_back(x+y);
                        }
                        else if (s[i]=='-')
                        {
                            ans.push_back(x-y);
                        }
                        else
                        {
                            ans.push_back(x*y);
                        }
                    }
                }
            }
        }

        if (ans.empty())
        {
            ans.push_back(stoi(s));
        }

        return ans;
    }

    vector<int> diffWaysToCompute(string expression)
    {
        return helper(expression);        
    }
};