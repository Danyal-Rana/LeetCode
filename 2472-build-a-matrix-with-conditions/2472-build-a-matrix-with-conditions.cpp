class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Helper function to perform topological sort
        auto topologicalSort = [](int k, const vector<vector<int>>& conditions) {
            vector<vector<int>> graph(k + 1);
            vector<int> inDegree(k + 1, 0);
            
            for (const auto& condition : conditions) {
                graph[condition[0]].push_back(condition[1]);
                inDegree[condition[1]]++;
            }
            
            queue<int> q;
            for (int i = 1; i <= k; ++i) {
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
            
            vector<int> order;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                order.push_back(node);
                
                for (int neighbor : graph[node]) {
                    if (--inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
            
            if (order.size() != k) return vector<int>(); // Cycle detected
            return order;
        };
        
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);
        
        if (rowOrder.empty() || colOrder.empty()) return {}; // If there's a cycle
        
        unordered_map<int, int> rowPosition;
        unordered_map<int, int> colPosition;
        
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }
        
        vector<vector<int>> result(k, vector<int>(k, 0));
        for (int num = 1; num <= k; ++num) {
            int row = rowPosition[num];
            int col = colPosition[num];
            result[row][col] = num;
        }
        
        return result;
    }
};