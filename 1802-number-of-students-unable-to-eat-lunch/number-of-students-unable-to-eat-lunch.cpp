class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches)
    {
        int counter[] = {0, 0};

        for (auto i : students)
        {
            counter[i]++;
        }

        int i=0;
        int n = sandwiches.size();

        while (i<n && counter[sandwiches[i]]>0)
        {
            counter[sandwiches[i]]--;
            i++;
        }

        return n-i;
    }
};