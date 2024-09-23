class Solution {
public:

    int t[51];

    int helper(int i, string &s, unordered_set<string> &st, int &n)
    {
        if (i >= n)
            return 0;

        if (t[i] != -1)
        {
            return t[i];
        }

        int ans = 1+helper(i+1, s, st, n);

        for (int j=i; j<n; j++)
        {
            string curr = s.substr(i, j-i+1);

            if (st.count(curr))
            {
                ans = min (ans, helper(j+1, s, st, n));
            }
        }

        return t[i] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary)
    {
        int n = s.size();
        unordered_set <string> st(dictionary.begin(), dictionary.end());
        memset(t, -1, sizeof(t));

        return helper(0, s, st, n);
    }
};