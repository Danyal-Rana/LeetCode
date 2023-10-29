class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles)
    {
        vector<int> myVector;
        
        for (vector<int> rectangle : rectangles)
        {
            myVector.push_back (min (rectangle[0], rectangle[1]));
        }
        
        int maxLength = *max_element (myVector.begin(), myVector.end());
        
        int maxRec = count (myVector.begin(), myVector.end(), maxLength);
        
        return maxRec;
    }
};