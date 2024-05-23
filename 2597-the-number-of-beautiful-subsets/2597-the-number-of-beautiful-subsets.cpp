class Solution {
public:
    unordered_map<int , int> count;
    int solve(vector<int> & nums , int index  , int k){
        if(index>=nums.size()){
            return 1;
        }

        //unpick
        int unpick = solve(nums , index+1 , k);

        //pick
        int pick = 0;
        if(count[nums[index]-k]==0 && count[nums[index]+k]==0 ){
            count[nums[index]]++;
            pick = solve(nums , index+1 , k);
            count[nums[index]]--;
        } 

        return pick + unpick;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        //empty hata diya!
        return solve(nums, 0 , k)-1;
    }
};