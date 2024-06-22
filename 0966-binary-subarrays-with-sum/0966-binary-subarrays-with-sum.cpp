class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        if (goal < 0)
        {
            return 0;
        }

        int l = 0;
        int r = 0;
        int n = nums.size();
        int sum = 0;
        int myCounter = 0;

        while (r < n)
        {
            sum += nums[r];

            while (sum > goal)
            {
                sum -= nums[l++];
            }

            myCounter += (r-l+1);
            r++;
        }

        int goalessOne = goalLessThanOne(nums, goal-1);
        return myCounter - goalessOne;
    }

    int goalLessThanOne(vector<int>& nums, int goal) {
        if(goal<0) return 0;
        int l=0;
        int r= 0;
        int count =0;
        int sum = 0 ;
        
        while(r < nums.size()){
            sum = sum+ nums[r];
            while(sum>goal){
                sum = sum -nums[l];
                l++;
            }
            if(sum<=goal){ 
                count = count + r-l+1;
            }
            r++;
        }
        return count;
    }
};