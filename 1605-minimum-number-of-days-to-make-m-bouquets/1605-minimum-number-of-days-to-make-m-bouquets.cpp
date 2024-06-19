class Solution {
public:

    bool helper(vector<int>& bloomDay, int m, int k, int mid)
    {
        int n = bloomDay.size();
        int flower = 0;
        int bouquet = 0;

        for (int i=0; i<n; i++)
        {
            if (bloomDay[i] <= mid)
            {
                flower++;
            }
            else
            {
                flower = 0;
            }

            if (flower >= k)
            {
                bouquet++;
                flower = 0;
            }
        }

        if (bouquet >= m)
        {
            return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k)
    {
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        int result = -1;
        int n = bloomDay.size();

        if (m > n / k) {
            return -1;
        }        

        while (left <= right)
        {
            int mid = (left+right)/2;

            if (helper(bloomDay, m, k, mid))
            {
                result = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }

        return result;
    }
};