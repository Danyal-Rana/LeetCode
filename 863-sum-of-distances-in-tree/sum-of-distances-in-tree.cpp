class Solution {
public:
    vector<vector<int>> adj;
    vector<int> sum, cnt;
    void build_adj(int n, vector<vector<int>>& edges){
        adj.resize(n);
        for(auto& e: edges){
            int v=e[0], w=e[1];
            adj[v].push_back(w);
            adj[w].push_back(v);       
        }
    }
    void dfs0(int i, int parent=-1){
        for(int j: adj[i]){
            if (j==parent) continue;
            dfs0(j, i);
            cnt[i]+=cnt[j];
            sum[i]+=sum[j]+cnt[j];//subtree for root=i
        }
    }
    void reroot(int i, int parent, int n){
        for (int j: adj[i]){
            if (j==parent) continue;
            sum[j]=sum[i]+n-2*cnt[j];
            reroot(j, i, n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    //    if (n==1) return {0};
        build_adj(n, edges);
        sum.assign(n, 0);
        cnt.assign(n, 1);
        dfs0(0);
        reroot(0, -1, n);
        return sum;
    }
};