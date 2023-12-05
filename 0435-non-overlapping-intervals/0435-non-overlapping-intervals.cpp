class Solution {
public:
    
    static bool helper (vector<int>&a, vector<int>&b)
    {
        return b[1]>a[1];
    }
    
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int myCounter = 0;
        sort (intervals.begin(), intervals.end(), helper);
        int t = INT_MIN;
        
        for (int i=0; i<intervals.size(); i++)
        {
            if (intervals[i][0] >= t)
            {
                t = intervals[i][1];
            }
            else
            {
                myCounter++;
            }
        }
        
        return myCounter;
    }
};