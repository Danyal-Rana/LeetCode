class Solution {
public:
    int countSeniors(vector<string>& details)
    {
        int totalSeniors = 0;

        for (auto d : details)
        {
            string ageStr = d.substr(11, 2);
            int age = stoi(ageStr);

            if (age > 60)
            {
                totalSeniors++;
            }
        }

        return totalSeniors;        
    }
};