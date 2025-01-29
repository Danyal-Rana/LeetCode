class Solution {
public:

    bool dfs(unordered_map<int, vector<int>> &adj, int u, int v, vector<bool> &visited)
    {
        visited[u] = true;

        if (u==v)
        {
            return true;
        }

        for(int &ngbr : adj[u]) 
        {
            if(visited[ngbr]) 
            {
                continue;
            }

            if(dfs(adj, ngbr, v, visited)) 
            {
                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            vector<bool> visited(n, false);
            if(adj.find(u) != adj.end() && adj.find(v) != adj.end() && dfs(adj, u, v, visited))
            {
                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};