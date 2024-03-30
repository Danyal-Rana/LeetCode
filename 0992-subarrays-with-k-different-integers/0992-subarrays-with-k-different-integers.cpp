class Solution {
public:

    int checkSubarrayAtmostK(vector<int>& nums, int k){
        int n=nums.size();
        int i=0,j=0,count=0;
        unordered_map<int , int> mpp;

        while(j<n){
            mpp[nums[j]]++;


            while(i<=j && mpp.size()>k ){

                mpp[nums[i]]--;

                if( mpp[nums[i]] == 0 )  mpp.erase(nums[i]);

                i++;
            }

            count+=(j-i)+1;
            j++;
        }

        return count;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return checkSubarrayAtmostK(nums, k)-checkSubarrayAtmostK(nums , k-1);
    }
};