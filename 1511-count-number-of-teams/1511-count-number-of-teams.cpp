class Solution {
public:
    int numTeams(vector<int>& rating)
    {
        int n = rating.size();
        int ans = 0;

        for (int i=0; i<n-1; i++)
        {
            int leftLarger = 0;
            int leftSmaller = 0;
            int rightLarger = 0;
            int rightSmaller = 0;

            for(int j=0; j<i; j++)
            {
                if (rating[j] > rating[i])
                {
                    leftLarger++;
                }
                else if (rating[j] < rating[i])
                {
                    leftSmaller++;
                }
            }

            for (int j=i+1; j<n; j++)
            {
                if (rating[j] > rating[i])
                {
                    rightLarger++;
                }
                else if (rating[j] < rating[i])
                {
                    rightSmaller++;
                }
            }

            ans += rightLarger*leftSmaller + rightSmaller*leftLarger;
        }
        return ans;
    }
};