class Solution {
public:
    long long maxKelements(vector<int>& nums, int k)
    {
        long long sum = 0;

        priority_queue<int> pq(nums.begin(), nums.end());

        while (k--)
        {
            int maxNum = pq.top();
            pq.pop();

            sum += maxNum;

            maxNum = ceil(maxNum/3.0);
            
            pq.push(maxNum);
        }

        return sum ;        
    }
};