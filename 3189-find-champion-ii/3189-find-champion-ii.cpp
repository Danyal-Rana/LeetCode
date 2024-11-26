class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges)
    {
        vector<int> indegree(n, 0);

        for(vector<int> &edge : edges)
        {
            indegree[edge[1]]++;
        }

        int champ = 0;
        int totalChamps = 0;

        for(int i=0; i<n; i++)
        {
            if (indegree[i]==0)
            {
                champ = i;
                totalChamps++;
                if (totalChamps>=2)
                {
                    return -1;
                }
            }
        }

        return champ;
    }
};