class Solution 
{
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
    {
        vector<int> ans;
        vector<pair<int, int>> myPair;

        for (int i = 0; i < nums.size(); i++) 
        {
            int temp = nums[i];
            int temp2 = 0;
            int j = 1;

            if (temp == 0) 
            {
                temp2 = mapping[0]; // Handle the case when the number is 0
            } 
            else 
            {
                while (temp > 0) 
                {
                    int x = temp % 10;
                    temp = temp / 10;
                    x = mapping[x];
                    temp2 = (x * j) + temp2;
                    j = j * 10;
                }
            }

            myPair.push_back({temp2, nums[i]});
        }

        sort(myPair.begin(), myPair.end(), [](const pair<int, int>& a, const pair<int, int>& b) 
        {
            return a.first < b.first;
        });

        for (int i = 0; i < nums.size(); i++) 
        {
            ans.push_back(myPair[i].second);
        }

        return ans;
    }
};