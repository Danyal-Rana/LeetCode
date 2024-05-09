class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        sort(happiness.rbegin(), happiness.rend());
        
        long long ans = 0;
        
        for (int i=0; i<happiness.size() and k>0; i++)
        {
            if (happiness[i]-i<=0)
                break;
            else
            {
                ans += (happiness[i]-i);
                k--;
            }
        }
        
        return ans;
    }
};