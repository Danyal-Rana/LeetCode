class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int left = 0;
        int right = height.size()-1;
        int maxArea = INT_MIN;
        
        while (left < right)
        {
            int cArea = min(height[left], height[right]) * (right-left);
            maxArea = max (cArea, maxArea);
            
            if (height[right] < height[left])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        
        
        return maxArea;
    }
};