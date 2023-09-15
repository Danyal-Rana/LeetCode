class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {
        int ans = 0;
        if (k<= numOnes+numZeros)
        {
            ans = min (k, numOnes);
        }
        else
        {
            ans = numOnes - (k-(numOnes+numZeros));
        }
        return ans;
    }
};