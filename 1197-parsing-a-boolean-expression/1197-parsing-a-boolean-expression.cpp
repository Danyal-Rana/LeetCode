class Solution {
public:

    char helper(vector<char> &values, char opr)
    {
        if (opr == '!')
        {
            return values[0]=='t' ? 'f' : 't';
        }
        else if (opr == '&')
        {
            for (int i=0; i<values.size(); i++)
            {
                if (values[i]=='f')
                {
                    return 'f';
                }
            }
            return 't';
        }
        else if (opr == '|')
        {
            for (int i=0; i<values.size(); i++)
            {
                if (values[i]=='t')
                {
                    return 't';
                }
            }
            return 'f';
        }

        return 't';
    }

    bool parseBoolExpr(string expression)
    {
        int n = expression.size();
        stack<char> st;

        for (int i=0; i<n; i++)
        {
            if (expression[i]==',')
            {
                continue;
            }

            if (expression[i]==')')
            {
                vector<char> values;

                while (st.top() != '(')
                {
                    values.push_back(st.top());
                    st.pop();
                }

                st.pop(); // removing (
                char opr = st.top();
                st.pop();

                st.push(helper(values, opr));
            }
            else
            {
                st.push(expression[i]);
            }
        }

        return st.top()=='t' ? true : false;
    }
};