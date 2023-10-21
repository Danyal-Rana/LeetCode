class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();
        
        stack<int> myStack;
        vector<int> myVector (n, -1);
        
        for (int i=n*2-1; i>=0; i--)
        {
            while (!myStack.empty() && myStack.top() <= nums[i%n])
            {
                myStack.pop();
            }
            
            if (!myStack.empty() && i<n)
            {
                myVector[i] = myStack.top();
            }
            
            myStack.push (nums[i%n]);
        }
        
        return myVector;
    }
};