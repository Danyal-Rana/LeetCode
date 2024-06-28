class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads)
    {
        vector<int> degree(n, 0);
        for (auto edge : roads)
        {
            int u = edge[0];
            int v = edge[1];
            degree[u]++;
            degree[v]++;
        }

        sort(degree.begin(), degree.end());
        long long ans = 0;
        long long val = 1;

        for (auto d : degree)
        {
            ans += val*d;
            val++;
        }
        return ans;
    }
};