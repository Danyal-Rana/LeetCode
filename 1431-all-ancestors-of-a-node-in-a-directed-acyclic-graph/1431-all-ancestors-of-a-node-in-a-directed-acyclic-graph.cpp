class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, vector<int>> sortedAncestors;

        vector<int> inDegree (n, 0);
        unordered_map<int, vector<int>> gr;

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            inDegree[v]++;
            gr[u].push_back(v);
        }

        queue<int> q;
        unordered_map<int, int> vis;

        for (int node=0; node<n; node++)
        {
            if (inDegree[node] == 0)
            {
                q.push(node);
            }
        }

        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                int cNode = q.front();
                q.pop();

                vector<int> &anc = sortedAncestors[cNode];

                for (auto child : gr[cNode])
                {
                    inDegree[child]--;
                    vector<int> childParent = {cNode};

                    sortedAncestors[child] = merge(anc, sortedAncestors[child]);
                    sortedAncestors[child] = merge(sortedAncestors[child], {cNode});

                    if (inDegree[child] == 0)
                    {
                        q.push(child);
                    }
                }
            }
        }

        vector<vector<int>> ans;

        for (int node=0; node<n; node++)
        {
            ans.push_back(sortedAncestors[node]);
        }

        return ans;
    }

    vector<int> merge(const vector<int>& a, const vector<int>& b)
    {
        vector<int> result;
        int i = 0;
        int j = 0;

        while (i < a.size() && j < b.size()) 
        {
            if (a[i] < b[j]) 
            {
                result.push_back(a[i++]);
            } else if (a[i] > b[j]) 
            {
                result.push_back(b[j++]);
            } 
            else 
            {
                result.push_back(a[i]);
                i++;
                j++;
            }
        }

        while (i < a.size()) 
        {
            result.push_back(a[i++]);
        }

        while (j < b.size()) 
        {
            result.push_back(b[j++]);
        }

        return result;
    }

};