class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        int initial = 0;
        int current = 0;
        int maxExtra = 0;

        for (int i=0; i<customers.size(); i++)
        {
            if (grumpy[i] == 0)
            {
                initial += customers[i];
            }
            else if (i<minutes)
            {
                current += customers[i];
            }
        }

        maxExtra = current;

        for (int i=minutes; i<customers.size(); i++)
        {
            current += customers[i]*grumpy[i];
            current -= customers[i-minutes]*grumpy[i-minutes];
            maxExtra = max(maxExtra, current);
        }

        return maxExtra + initial;
    }
};