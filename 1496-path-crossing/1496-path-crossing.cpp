class Solution {
public:
    bool isPathCrossing(string path)
    {
        set<pair<int, int>> mySet;
        int x = 0;
        int y = 0;
        mySet.insert ({x, y});
        
        for (auto i : path)
        {
            if (i == 'N')
            {
                y++;
            }
            else if (i == 'E')
            {
                x++;
            }
            else if (i == 'W')
            {
                x--;
            }
            else if (i == 'S')
            {
                y--;
            }
            
            
            if (mySet.count ({x,y}) > 0)
            {
                return true;
            }
            
            mySet.insert ({x, y});
        }
        
        return false;
    }
};