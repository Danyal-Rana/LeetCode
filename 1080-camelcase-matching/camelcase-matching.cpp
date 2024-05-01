class Solution {
public:

    bool helper (string str, string pattern)
    {
        int i = 0;
        int cap = 0;

        for (int j=0; j<str.size(); j++)
        {
            if (i<pattern.size() && str[j]==pattern[i])
            {
                i++;
            }
            else if (str[j]>='A' and str[j]<='Z')
            {
                cap++;
            }
        }

        return (i==pattern.size() and cap == 0);
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern)
    {
        int n = queries.size();
        vector<bool> ans (n);

        for (int i=0; i<n; i++)
        {
            ans[i] = helper(queries[i], pattern);
        }

        return ans;
    }
};