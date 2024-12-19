class Solution {
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> prefixMax(n);
        vector<int> suffixMin(n);
        int chunks = 0;

        prefixMax[0] = arr[0];
        suffixMin[n-1] = arr[n-1];
        for(int i=1; i<n; i++)
        {
            prefixMax[i] = max(prefixMax[i-1], arr[i]);
        }

        for (int i=n-2; i>=0; i--)
        {
            suffixMin[i] = min(suffixMin[i+1], arr[i]);
        }

        for(int i=0; i<n; i++)
        {
            int preMax = i>0 ? prefixMax[i-1] : -1;
            int afterMin = suffixMin[i];

            if (preMax < afterMin)
            {
                chunks++;
            }
        }

        return chunks;
    }
};