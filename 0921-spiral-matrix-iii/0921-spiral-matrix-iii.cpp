class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> directions = {{0,1}, {1, 0}, {0,-1}, {-1,0}};

        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});

        int steps = 0;
        int dir = 0;

        while (ans.size() < rows*cols)
        {
            if (dir==0 || dir==2)
            {
                steps++;
            }

            for (int count=0; count<steps; count++)
            {
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                if (rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)
                {
                    ans.push_back({rStart, cStart});
                }
            }

            dir = (dir+1)%4;
        }

        return ans;
    }
};