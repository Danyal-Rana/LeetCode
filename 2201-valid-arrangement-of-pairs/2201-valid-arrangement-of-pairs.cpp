class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs)
    {
        unordered_map<int, vector<int>> adj;

        unordered_map<int, int> inDegree;
        unordered_map<int, int> outDegree;

        for (auto &edg : pairs)
        {
            int u = edg[0];
            int v = edg[1];

            adj[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        // finding startNode
        int startNode = pairs[0][0];
        for (auto &it : adj)
        {
            int node = it.first;
            if (outDegree[node]-inDegree[node]==1)
            {
                startNode = node;
                break;
            }
        }

        //dfs
        stack<int> st;
        vector<int> eulerPath;
        st.push(startNode);

        while (!st.empty())
        {
            int curr = st.top();
            if (!adj[curr].empty())
            {
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }
            else
            {
                eulerPath.push_back(curr);
                st.pop();
            }
        }

        reverse(eulerPath.begin(), eulerPath.end());
        vector<vector<int>> ans;
        for (int i=0; i<eulerPath.size()-1; i++)
        {
            ans.push_back({eulerPath[i], eulerPath[i+1]});
        }

        return ans;
    }
};