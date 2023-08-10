class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        for (int i=m,j=0; i<nums1.size(); i++,j++)
        {
            nums1[i] = nums2[j];
        }
        
        for (int i=0; i<m+n-1; i++)
        {
            for (int j=i+1; j<m+n; j++)
            {
                if (nums1[i] > nums1[j])
                    swap (nums1[i], nums1[j]);
            }
        }
    }
};