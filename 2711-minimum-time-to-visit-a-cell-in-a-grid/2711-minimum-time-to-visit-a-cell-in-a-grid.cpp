class Solution {
public:
    #define P pair<int, pair<int, int>>

    vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minimumTime(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        pq.push({0, {0, 0}});
        ans[0][0] = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while (!pq.empty()) 
        {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == m - 1 && col == n - 1)
                return ans[m - 1][n - 1];

            if (visited[row][col])
                continue;

            visited[row][col] = true;

            for (auto &dir : directions) 
            {
                int i = row + dir[0];
                int j = col + dir[1];

                if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
                    continue;

                if (grid[i][j] <= time) 
                {
                    pq.push({time + 1, {i, j}});
                    ans[i][j] = time + 1;
                }
                else if ((grid[i][j]-time )% 2 == 0) 
                {
                    pq.push({grid[i][j] + 1, {i, j}});
                    ans[i][j] = grid[i][j] + 1;
                }
                else 
                {
                    pq.push({grid[i][j], {i, j}});
                    ans[i][j] = grid[i][j];
                }
            }
        }

        return ans[m - 1][n - 1];
    }
};