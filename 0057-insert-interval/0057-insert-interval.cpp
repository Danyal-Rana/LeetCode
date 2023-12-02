class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> myVector;
        
        int i = 0;
        int n = intervals.size();
        
        while (i<n && intervals[i][1]<newInterval[0])
        {
            myVector.push_back (intervals[i++]);
        }
        
        vector<int> mI = newInterval;
        while (i<n && intervals[i][0] <= newInterval[1])
        {
            mI[0] = min (mI[0], intervals[i][0]);
            mI[1] = max (mI[1], intervals[i][1]);
            i++;
        }
        myVector.push_back (mI);
        
        while (i<n)
        {
            myVector.push_back (intervals[i++]);
        }
        
        return myVector;
    }
};