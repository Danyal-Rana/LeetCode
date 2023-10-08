class Solution
{
public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        double mySlope = static_cast<double> (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);

        for (int i = 2; i < coordinates.size(); i++)
        {
            if (coordinates[i][0] == coordinates[0][0])
            {
                if (coordinates[1][0] != coordinates[0][0])
                {
                    return false;
                }
            }
            else
            {
                double currentSlope = static_cast<double> (coordinates[i][1] - coordinates[0][1]) / (coordinates[i][0] - coordinates[0][0]);

                if (mySlope != currentSlope)
                {
                    return false;
                }
            }
        }
        return true;
    }
};