class Solution {
public:
    bool isRobotBounded(string instructions)
    {
        char currDir = 'N';
        int x = 0;
        int y = 0;

        for (int i=0; i<instructions.length(); i++)
        {
            if(instructions[i] == 'G')
            {
                y += currDir=='N' ? 1 : 0;
                y += currDir=='S' ? -1 : 0;
                x += currDir=='E' ? 1 : 0;
                x += currDir=='W' ? -1 : 0;
            }
            else
            {
                char incoming = instructions[i];

                if (currDir == 'N')
                {
                    currDir = incoming=='L' ? 'W' : 'E';
                }
                else if (currDir == 'S')
                {
                    currDir = incoming=='L' ? 'E' : 'W';
                } 
                else if (currDir == 'W')
                {
                    currDir = incoming=='L' ? 'S' : 'N';
                }
                else
                {
                    currDir = incoming=='L' ? 'N' : 'S';
                }
            }
        }

        return (x==0 && y==0) || currDir != 'N';
    }
};