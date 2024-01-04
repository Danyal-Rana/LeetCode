class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        unordered_map <int, int> m;
        
        for (auto i : nums)
        {
            m[i]++;
        }
        
        int ans = 0;
        
        for (auto [k,f] : m)
        {
            if (f==1)
            {
                return -1;
            }
            ans += f/3 + (f%3+1)/2;
        }
        
        return ans;
    }
};