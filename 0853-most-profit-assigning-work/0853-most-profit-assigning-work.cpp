class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        int n = profit.size();
        int m = worker.size();

        vector<pair<int, int>> vp;
        for (int i=0; i<n; i++)
        {
            vp.push_back ({difficulty[i], profit[i]});
        }

        sort(vp.begin(), vp.end());
        sort(worker.begin(), worker.end());

        int profSum = 0;
        int maxProf = 0;
        int j = 0;

        for (int i=0; i<m; i++)
        {
            while (j<m and vp[j].first <= worker[i])
            {
                maxProf = max(maxProf, vp[j++].second);
            }
            profSum += maxProf;
        }

        return profSum;
    }
};