class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {      
          vector <vector<int>> myPascal;

          for (int i=0; i<numRows; i++)
          {
              vector <int> myTemp (i+1, 1);

              for (int j=1; j<i; j++)
              {
                  myTemp [j] = myPascal[i-1][j-1] + myPascal[i-1][j];
              }
              myPascal.push_back (myTemp);
          }
          return myPascal;
    }
};