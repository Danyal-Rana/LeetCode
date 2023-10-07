class Solution
{
public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        if (coordinates.size() < 2) {
            return true; // Edge case with 0 or 1 point is considered a straight line.
        }

        double mySlope = static_cast<double>(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);

        for (int i = 2; i < coordinates.size(); i++)
        {
            if (coordinates[i][0] == coordinates[0][0]) {
                // Special case: Vertical line
                if (coordinates[1][0] != coordinates[0][0]) {
                    return false; // Not a straight line if any other point has a different x-coordinate.
                }
            } else {
                double currentSlope = static_cast<double>(coordinates[i][1] - coordinates[0][1]) / (coordinates[i][0] - coordinates[0][0]);

                if (mySlope != currentSlope)
                {
                    return false;
                }
            }
        }
        return true;
    }
};