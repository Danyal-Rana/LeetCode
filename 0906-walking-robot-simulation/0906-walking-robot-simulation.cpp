class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        unordered_set<string> st;   

        for (vector<int> &obs : obstacles)
        {
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int x = 0;
        int y = 0;
        int maxDis = 0;

        pair<int, int> dir = {0, 1};

        for (int i=0; i<commands.size(); i++)
        {
            if (commands[i] == -2)
            {
                dir = {-dir.second, dir.first};
            }
            else if (commands[i] == -1)
            {
                dir = {dir.second, -dir.first};
            }
            else
            {
                for (int j=0; j<commands[i]; j++)
                {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    string curKey = to_string(newX) + "_" + to_string(newY);

                    if (st.find(curKey) != st.end())
                    {
                        break;
                    }

                    x = newX;
                    y = newY;
                }
            }

            maxDis = max(maxDis, x*x + y*y);
        }

        return maxDis;
    }
};