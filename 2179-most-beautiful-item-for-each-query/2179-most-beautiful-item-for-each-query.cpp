class Solution 
{
public:

    int modBinarySearch(int x, vector<vector<int>>& items)
    {
        int left = 0;
        int right = items.size() - 1;
        int mid;
        int result = 0; 
        
        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (items[mid][0] <= x)
            {
                result = items[mid][1];
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    {
        int n = items.size();
        int m = queries.size();

        vector<int> ans(m);
        sort(items.begin(), items.end());

        int maxi = items[0][1];
        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, items[i][1]);
            items[i][1] = maxi;
        }

        for (int i = 0; i < m; i++)
        {
            ans[i] = modBinarySearch(queries[i], items);
        }

        return ans;
    }
};