#define pi pair<int,int>
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Variation of Dijkstra's Algorithm
        vector<int> adj[n];
        for(vector<int> &edge :edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // {time, node}
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});
        // first min dist
        vector<int> dist1(n, 1e9);
        // second min dist 
        vector<int> dist2(n, 1e9); 
        dist1[0] = 0;
        
        while(!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();
            if(node == n-1 && dist2[node] != 1e9) return dist2[node];

            if((currTime / change) & 1) currTime += change - (currTime % change);
            currTime += time;

            for(int &neigh :adj[node]) {
                if(dist1[neigh] == 1e9) {
                    dist1[neigh] = currTime;
                    pq.push({currTime, neigh});
                }
                else if(dist2[neigh] == 1e9 && dist1[neigh] != currTime) {
                    dist2[neigh] = currTime;
                    pq.push({currTime, neigh});
                }
            }
        }
        return -1;
    }
};