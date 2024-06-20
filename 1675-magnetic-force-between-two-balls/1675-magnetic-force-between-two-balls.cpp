class Solution {
public:

    bool helper(int mid, vector<int>& position, int m)
    {
        int mPlaced = 1;
        int lastPosition = position[0];

        for (int i=1; i<position.size(); i++)
        {
            if ((position[i]-lastPosition) >= mid)
            {
                if (++mPlaced == m)
                {
                    return true;
                }
                lastPosition = position[i];
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m)
    {
        sort(position.begin(), position.end());
        long long low = 1;
        long long high = *max_element(position.begin(), position.end());
        long long mid;
        long long ans = 0;

        while (high >= low)
        {
            mid = (high+low)/2;

            if (helper(mid, position, m))
            {
                low = mid+1;
                ans = mid;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return ans;
    }
};