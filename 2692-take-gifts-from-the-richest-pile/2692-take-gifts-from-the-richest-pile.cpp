class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k)
    {
        int n = gifts.size();

        for (int i=0; i<k; i++)
        {
            int richestIdx = 0;

            for(int j=0; j<n; j++)
            {
                if(gifts[richestIdx]<gifts[j])
                {
                    richestIdx = j;
                }
            }

            gifts[richestIdx] = sqrt(gifts[richestIdx]);
        }

        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};