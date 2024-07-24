class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int V = isConnected.size();
        vector<int> adj[V];

        // converting matrix to list
        for (int i=0; i<V; i++)
        {
            for (int j=0; j<V; j++)
            {
                if (isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // creating vectors
        vector<int> vis(V);
        int totalComponents = 0;

        for (int i=0; i<V; i++)
        {
            if (vis[i] == 0)
            {
                dfsHelper(i, adj, vis);
                totalComponents++;
            }
        }
        return totalComponents;
    }

    void dfsHelper(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;

        for (auto i : adj[node])
        {
            if(!vis[i])
            {
                dfsHelper(i, adj, vis);
            }
        }
    }
};