class Solution {
public:
    int findMinDifference(vector<string>& timePoints)
    {
        vector<int> mins;
        int n = timePoints.size();

        for (int i=0; i<n; i++)
        {
            string currStr = timePoints[i];

            string hoursSubStr = currStr.substr(0, 2);
            string minSubStr = currStr.substr(3);

            int temp = stoi(hoursSubStr)*60 + stoi(minSubStr);

            mins.push_back(temp);
        }

        sort(mins.begin(), mins.end());

        int result = INT_MAX;

        for (int i=1; i<n; i++)
        {
            result = min(result, mins[i]-mins[i-1]);
        }

        return min(result, (1440-mins[n-1])+mins[0]);
    }
};