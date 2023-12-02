class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        
        int leftProduct = 1;
        int rightProduct = 1;
        int maxProduct = nums[0];
        
        for (int i=0; i<n; i++)
        {
            leftProduct = leftProduct==0 ? 1 : leftProduct;
            rightProduct = rightProduct==0 ? 1 : rightProduct;
            
            leftProduct *= nums[i];
            rightProduct *= nums[n-1-i];
            
            maxProduct = max (maxProduct, max(leftProduct, rightProduct));
        }
        
        return maxProduct;
    }
};