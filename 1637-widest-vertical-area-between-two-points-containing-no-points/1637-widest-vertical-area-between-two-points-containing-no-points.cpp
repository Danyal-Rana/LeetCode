class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        int r = 0;
        
        vector<int> temp;
        
        for (int i=0; i<points.size(); i++)
        {
            temp.push_back (points[i][0]);
        }
        
        sort (temp.begin(), temp.end());
        
        for (int i=1; i<temp.size(); i++)
        {
            r = max (r, temp[i]-temp[i-1]);
        }
        
        return r;
    }
};