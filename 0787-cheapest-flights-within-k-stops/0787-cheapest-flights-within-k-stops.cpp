class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        unordered_map<long long, vector<pair<long, long>>> graph;
        for (auto &fl : flights)
        { 
            int currSrc = fl[0], neigh = fl[1], neighDistFromSrc = fl[2];
            graph[currSrc].push_back(make_pair(neigh, neighDistFromSrc));
        }
        vector<long long> distFromSource(n, INT_MAX);
        queue<pair<long, long>> que;
        long long minLen = INT_MAX, stops = 0;
        que.push({src, 0});
        while (!que.empty() && stops <= k)
        {
            int size = que.size();
            while (size-- > 0)
            {
                auto currPr = que.front();
                que.pop();
                for (auto neigh : graph[currPr.first])
                {
                   if(distFromSource[neigh.first] > currPr.second + neigh.second){
                      distFromSource[neigh.first] = currPr.second + neigh.second;
                      if(neigh.first == dst) 
                       minLen = min(minLen, distFromSource[neigh.first]);
                      que.push({neigh.first, distFromSource[neigh.first]});
                   }
                }
            }
            stops++;
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};