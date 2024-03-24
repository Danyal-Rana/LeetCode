class Solution {
public:
    double average(vector<int>& salary)
    {
        sort (salary.begin(), salary.end());
        double totalSalaries = 0;
        
        for (int i=1; i<salary.size()-1; i++)
        {
            totalSalaries += salary[i];
        }
        
        return totalSalaries/(salary.size()-2);
    }
};