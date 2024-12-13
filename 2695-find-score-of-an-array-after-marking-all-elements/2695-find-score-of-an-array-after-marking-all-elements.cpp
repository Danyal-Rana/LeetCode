class Solution {
public:
    #define P pair<int, int>
    long long findScore(vector<int>& nums)
    {
        int n = nums.size();
        vector<bool> visited(n, false);

        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i=0; i<n; i++)
        {
            pq.push({nums[i], i});
        }

        long long ans = 0;
        while (!pq.empty())
        {
            P temp = pq.top();
            int ele = temp.first;
            int idx = temp.second;
            pq.pop();

            if (!visited[idx])
            {
                visited[idx] = true;
                ans += ele;

                if(idx-1>=0 && !visited[idx-1])
                {
                    visited[idx-1] = true;
                }

                if (idx+1<n && !visited[idx+1])
                {
                    visited[idx+1] = true;
                }
            }
        }
        return ans;
    }
};