class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        for (int i = 0; i < board.size(); ++i) 
        {
            for (int j = 0; j < board[0].size(); ++j) 
            {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) 
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int count)
    {
        if (count == word.size())
        {
            return true;
        }
        
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || word[count] != board[i][j])
        {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '*'; // marking visited
        
        bool isFound = dfs(board, word, i + 1, j, count + 1) ||
                      dfs(board, word, i - 1, j, count + 1) ||
                      dfs(board, word, i, j + 1, count + 1) ||
                      dfs(board, word, i, j - 1, count + 1);
        
        board[i][j] = temp; // backtracking
        
        return isFound;
    }
};