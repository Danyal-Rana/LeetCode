class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        stack<int> myStack;
        vector<int> myVector1 (nums1.size());
        vector<int> myVector2 (nums2.size());
        
        for (int i=nums2.size()-1; i>=0; i--)
        {
            while (!myStack.empty() && myStack.top() <= nums2[i])
            {
                myStack.pop();
            }
            
            if (myStack.empty())
            {
                myVector2[i] = -1;
            }
            else
            {
                myVector2[i] = myStack.top();
            }
            
            myStack.push (nums2[i]);
        }
        
        for (int i=0; i<nums1.size(); i++)
        {
            int j = 0;
            
            while (nums1[i] != nums2[j])
            {
                j++;
            }
            
            myVector1[i] = myVector2[j];
        }
        
        return myVector1;
    }
};