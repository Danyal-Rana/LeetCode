class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        vector<int> myCounter(k, 0);
        int sum = 0;

        for (auto i : nums)
        {
            sum += (i%k +k)%k;
            myCounter[sum%k]++;
        }        

        int result = myCounter[0];

        for (auto i : myCounter)
        {
            result += (i*(i-1))/2;
        }

        return result;
    }
};