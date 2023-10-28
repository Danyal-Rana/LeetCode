class Solution {
public:
    int sumOfUnique(vector<int>& nums)
    {
        unordered_map <int, int> count;
        int sum = 0;
        
        for (int i : nums)
        {
            count[i]++;
        }
        
        for (auto &pair : count)
        {
            if (pair.second == 1)
            {
                sum += pair.first;
            }
        }
        return sum;
    }
};