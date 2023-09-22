class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector <int> myRow;
        vector <vector<int>> myPascal(rowIndex + 1); 

        for (int i = 0; i <= rowIndex; i++) 
        {
            myPascal[i].resize(i + 1, 1);  

            for (int j = 1; j < i; j++)  
            {
                myPascal[i][j] = myPascal[i - 1][j - 1] + myPascal[i - 1][j];
            }
        }

        myRow = myPascal[rowIndex];

        return myRow;
    }
};