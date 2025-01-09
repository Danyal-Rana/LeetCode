class Solution {
public:
    int prefixCount(vector<string>& words, string pref)
    {
        int ans = 0;
        int n = words.size();
        int m = pref.size();

        for (int i=0; i<n; i++)
        {
            string s = words[i];

            if (s.substr(0, m) == pref)
                ans++;
        }

        return ans;
    }
};