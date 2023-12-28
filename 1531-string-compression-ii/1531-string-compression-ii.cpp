class Solution
{
private:
    vector<vector<int>> dp;
    int f(int ind, int k, string &s)
    {
        int n = s.length();

        if (n - ind <= k)
            return 0; 

        if (dp[ind][k] != -1)
            return dp[ind][k];

        int ans = k ? f(ind + 1, k - 1, s) : 1e5;

        int cnt = 1, removeCnt = 0;
        for (int i = ind + 1; i <= n; i++)
        {
            int cur = 1 + ((cnt > 99) ? 3 : (cnt > 9) ? 2
                                        : (cnt > 1)   ? 1
                                                      : 0) +
                      f(i, k - removeCnt, s);
            ans = min(ans, cur);
            if (i < n && s[i] == s[ind])
                cnt++;
            else if (k - removeCnt <= 0)
                break;
            else
                {
                    removeCnt++;
                }
        }
        return dp[ind][k] = ans;
    }

    public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        dp.resize(101, vector<int>(101, -1));
        return f(0, k, s);
    }
};