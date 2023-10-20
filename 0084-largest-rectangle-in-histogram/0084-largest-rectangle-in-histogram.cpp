class Solution {
public:
    vector<int> prevSmaller (vector<int> &heights)
    {
        stack<int> myStack;
        vector<int> myVector (heights.size());
        
        for (int i=0; i<heights.size(); i++)
        {
            while (!myStack.empty() && heights[myStack.top()] >= heights[i])
            {
                myStack.pop();
            }
            
            if (myStack.empty())
            {
                myVector[i] = -1;
            }
            else
            {
                myVector[i] = myStack.top();
            }
            
            myStack.push (i);
        }
        
        return myVector;
    }
    
    vector<int> nextSmaller (vector<int> &heights)
    {
        stack<int> myStack;
        vector<int> myVector (heights.size());
        
        for (int i=heights.size()-1; i>=0; i--)
        {
            while (!myStack.empty() && heights[myStack.top()] >= heights[i])
            {
                myStack.pop();
            }
            
            if (myStack.empty())
            {
                myVector[i] = heights.size();
            }
            else
            {
                myVector[i] = myStack.top();
            }
            
            myStack.push (i);
        }
        
        return myVector;
    }
    
    
    int largestRectangleArea(vector<int>& heights)
    {
        vector<int> prevSmal = prevSmaller(heights);
        vector<int> nextSmal = nextSmaller(heights);
        
        int maxArea = 0;
        
        for (int i=0; i<heights.size(); i++)
        {
            int area = (nextSmal[i]-prevSmal[i]-1)*heights[i];
            maxArea = max (area, maxArea);
        }
        
        return maxArea;        
    }
};