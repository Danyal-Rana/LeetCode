class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> v;
        
        sort (intervals.begin(), intervals.end());
        
        for (int i=0; i<intervals.size(); i++)
        {
            if (v.empty() || intervals[i][0]>v.back()[1])
            {
                v.push_back (intervals[i]);
            }
            else
            {
                vector<int> t (2, 0);
                t[0] = min (intervals[i][0], v.back()[0]);
                t[1] = max (intervals[i][1], v.back()[1]);
                v.pop_back ();
                v.push_back (t);
            }
        }
        
        return v;
    }
};