class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int n = points.size();

        int ans = 0;

        if(n==1)
            return 1;

        for(int i=0; i<n; i++)
        {
            unordered_map<double, int> m;

            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;

                double dy = points[j][1] - points[i][1];
                double dx = points[j][0] - points[i][0];

                double theta = atan2(dy, dx);

                m[theta]++;
            }

            for(auto &it : m)
            {
                ans = max(ans, it.second+1);
            }
        }

        return ans;
    }
};