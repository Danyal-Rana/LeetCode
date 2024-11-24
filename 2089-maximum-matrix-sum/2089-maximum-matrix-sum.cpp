class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        long long sum = 0;
        int negNums = 0;
        int smallestNum = INT_MAX;

        for (int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                sum += abs(matrix[i][j]);
                smallestNum = min(smallestNum, abs(matrix[i][j]));

                if (matrix[i][j]<0)
                    negNums++;
            }
        }

        return (negNums%2==0) ? sum : sum-(2*smallestNum);
    }
};