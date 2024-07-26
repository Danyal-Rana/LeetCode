class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (auto it : edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        // for itself
        for (int i=0; i<n; i++)
        {
            dist[i][i] = 0;
        }

        // floyed-warshal algo
        for (int k=0; k<n; k++)
        {
            for (int i=0; i<n; i++)
            {
                for (int j=0; j<n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    {
                        continue;
                    }

                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        

        // problem logic
        int cntCity = n;
        int cityNo = -1;

        for(int city=0; city<n; city++)
        {
            int counter = 0;
            for (int adjCity=0; adjCity<n; adjCity++)
            {
                if (dist[city][adjCity] <= distanceThreshold)
                {
                    counter++;
                }
            }
            
            if (counter <= cntCity)
            {
                cntCity = counter;
                cityNo = city;
            }
        }

        return cityNo;
    }
};