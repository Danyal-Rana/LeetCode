class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        unordered_map <int, int> myMap;

        int minE = *min_element (begin(nums), end(nums));
        int maxE = *max_element (begin(nums), end(nums));

        for (int &num : nums)
        {
            myMap[num]++;
        }

        int i = 0;

        for (int j=minE; j<=maxE; j++)
        {
            while (myMap[j] > 0)
            {
                nums[i++] = j;
                myMap[j]--;
            }
        }

        return nums;
    }
};