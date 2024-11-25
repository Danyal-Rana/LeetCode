class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board)
    {
        string start = "";
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++) // Fixed inner loop condition
            {
                start += to_string(board[i][j]);
            }
        }

        string goal = "123450";

        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 4, 2};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        queue<string> que;
        que.push(start);
        unordered_set<string> visited;
        visited.insert(start);
        int moves = 0;

        while (!que.empty())
        {
            int n = que.size();

            while (n--)
            {
                string curr = que.front();
                que.pop();
                if (curr == goal)
                    return moves;

                int idxOfZero = curr.find('0');

                for (int swapIdx : mp[idxOfZero])
                {
                    string newState = curr;
                    swap(newState[idxOfZero], newState[swapIdx]);

                    if (visited.find(newState) == visited.end())
                    {
                        que.push(newState);
                        visited.insert(newState);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};