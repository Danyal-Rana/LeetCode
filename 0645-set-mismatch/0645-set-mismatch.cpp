class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        unordered_map <int, int> m;
        
        vector<int> ans;
        
        int temp = 0;
        
        for (auto i : nums)
        {
            if (m.find(i)!=m.end())
            {
                temp = i;
            }
            m[i]++;
        }
        
        ans.push_back (temp);
        
        for (int i=1; i<=nums.size(); i++)
        {
            if (m.find(i)==m.end())
            {
                ans.push_back (i);
                break;
            }
        }
        return ans;
    }
};