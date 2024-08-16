class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int mini = arrays[0][0];
        int maxi = arrays[0][arrays[0].size()-1];

        int ans = INT_MIN;

        for (int i=1; i<arrays.size(); i++)
        {
            int curMini = arrays[i][0];
            int curMaxi = arrays[i][arrays[i].size()-1];

            int t1 = abs(maxi - curMini);
            int t2 = abs(curMaxi - mini);

            mini = min(mini, curMini);
            maxi = max(maxi, curMaxi);

            ans = max(ans, max(t1, t2));
        }

        return ans;
    }
};