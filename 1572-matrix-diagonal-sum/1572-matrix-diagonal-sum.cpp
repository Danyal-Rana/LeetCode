class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {        
        long long int totalSum = 0;
        
        for (int i=0,j=0; i<mat.size(); )
        {
            totalSum += mat[i++][j++];
        }
        
        for (int i=0,j=mat.size()-1; i<mat.size(); )
        {
            totalSum += mat[i++][j--];
        }
        
        if (mat.size()%2 != 0)
        {
            int particularElement = mat.size()/2;
            totalSum -= mat[particularElement][particularElement];
        }
        
        return totalSum;
    }
};