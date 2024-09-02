class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k)
    {
        long long sum = 0;

        for (int i=0; i<chalk.size(); i++)
        {
            sum += chalk[i];
        }

        int reminder = k%sum;

        for (int i=0; i<chalk.size(); i++)
        {
            if (reminder < chalk[i])
            {
                return i;
            }
            reminder -= chalk[i];
        }
        return 0;
    }
};