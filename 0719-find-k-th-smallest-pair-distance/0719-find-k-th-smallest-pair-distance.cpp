class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vec(n*(n-1)/2);

        int idx = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                vec[idx] = abs(nums[i] - nums[j]);
                idx++;
            }
        }
    //Time Complexity - Average : O(n) , Worst : O(n^2)
        nth_element(begin(vec), begin(vec)+(k-1), end(vec)); 
        return vec[k-1];
    }
};