class Solution {
public:

    bool helper(vector<vector<char>>& matrix, char ch)
    {
        if ((matrix[0][0] == ch && matrix[0][1] == ch && matrix[0][2] == ch) ||
            (matrix[1][0] == ch && matrix[1][1] == ch && matrix[1][2] == ch) ||
            (matrix[2][0] == ch && matrix[2][1] == ch && matrix[2][2] == ch) ||
            (matrix[0][0] == ch && matrix[1][0] == ch && matrix[2][0] == ch) ||
            (matrix[0][1] == ch && matrix[1][1] == ch && matrix[2][1] == ch) ||
            (matrix[0][2] == ch && matrix[1][2] == ch && matrix[2][2] == ch) ||
            (matrix[0][0] == ch && matrix[1][1] == ch && matrix[2][2] == ch) ||
            (matrix[0][2] == ch && matrix[1][1] == ch && matrix[2][0] == ch))
        {
            return true;
        }
        return false;
    }

    vector<vector<char>> makingMatrix(vector<vector<int>>& moves)
    {
        vector<vector<char>> ans(3, vector<char>(3, ' '));

        for (int i = 0; i < moves.size(); i++)
        {
            int j = moves[i][0];
            int k = moves[i][1];

            ans[j][k] = (i % 2 == 0) ? 'X' : 'O';
        }

        return ans;
    }


    string tictactoe(vector<vector<int>>& moves)
    {
        vector<vector<char>> ans = makingMatrix(moves);

        if (helper(ans, 'X'))
        {
            return "A";
        }
        else if (helper(ans, 'O'))
        {
            return "B";
        }
        return (moves.size() == 9) ? "Draw" : "Pending";
    }
};