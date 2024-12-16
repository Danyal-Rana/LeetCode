class Solution {
public:
    #define P pair<int, int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier)
    {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> minHeap;

        for(int i=0; i<n; i++)
        {
            minHeap.push({nums[i], i});
        }

        while (k--)
        {
            auto curr = minHeap.top();
            minHeap.pop();

            int ele = curr.first;
            int idx = curr.second;
            ele *= multiplier;
            nums[idx] = ele;
            minHeap.push({ele, idx});
        }

        return nums;
    }
};