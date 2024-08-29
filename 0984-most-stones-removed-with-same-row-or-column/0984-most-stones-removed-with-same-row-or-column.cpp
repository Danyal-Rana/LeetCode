class Solution {
    void dfs(vector<vector<int>>& grid ,int n ,int idx, int &cnt,vector<bool> & visited){
        visited[idx] = 1 ; 
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                if((grid[idx][0]==grid[i][0])||(grid[idx][1]==grid[i][1])){
                    cnt++;
                    dfs(grid,n,i,cnt,visited);
                }
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size() ;
        vector<bool> visited(n,false);
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(stones,n,i,cnt,visited);
            }
        }
        return cnt;
    }
};