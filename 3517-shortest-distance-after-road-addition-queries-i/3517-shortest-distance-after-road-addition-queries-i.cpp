class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int bfs (int n)
    {
        queue<int> que;
        que.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;

        int moves = 0;

        while (!que.empty())
        {
            int size = que.size();

            while (size--)
            {
                int node = que.front();
                que.pop();

                if (node == n-1)
                    return moves;
                
                for (auto &neighbors : adj[node])
                {
                    if (!visited[neighbors])
                    {
                        que.push(neighbors);
                        visited[neighbors] = true;
                    }
                }
            }
            moves++;
        }
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    {
        for (int i=0; i<n-1; i++)
        {
            adj[i].push_back(i+1);
        }

        int m = queries.size();
        vector<int> ans (m);

        for (int i=0; i<m; i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];

            adj[u].push_back(v);
            ans[i] = bfs(n);
        }
        return ans;
    }
};