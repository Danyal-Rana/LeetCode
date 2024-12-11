class Solution {
public:

    int findEquationValue(pair<int, int>& P1, pair<int, int>& P2, pair<int, int> P3) 
    {
        int x1 = P1.first;
        int x2 = P2.first;
        int x3 = P3.first;
        
        int y1 = P1.second;
        int y2 = P2.second;
        int y3 = P3.second;
        
        return (y3-y2)*(x2-x1)-(y2-y1)*(x3-x2);        
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees)
    {
        sort(trees.begin(), trees.end());

        vector<vector<int>> ans;

        deque<pair<int, int>> upper, lower;

        for (auto &points : trees)
        {
            int l = lower.size();
            int u = upper.size();

            while (l>=2 && findEquationValue(lower[l-2], lower[l-1], {points[0], points[1]})<0)
            {
                l--;
                lower.pop_back();
            }

            while (u>=2 && findEquationValue(upper[u-2], upper[u-1], {points[0], points[1]})>0)
            {
                u--;
                upper.pop_back();
            }

            upper.push_back({points[0], points[1]});
            lower.push_back({points[0], points[1]});
        }

        set<pair<int, int>> st;
        
        for(auto &point : upper) {
            st.insert(point);
        }
        
        for(auto &point : lower) {
            st.insert(point);
        }
        
        for(auto &point : st) {
            ans.push_back({point.first, point.second});
        }
        
        return ans;
    }
};