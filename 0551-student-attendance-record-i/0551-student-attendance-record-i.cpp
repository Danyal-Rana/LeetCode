class Solution {
public:
    bool checkRecord(string s)
    {
        int absentCounter = 0;
        int lateCounter = 0;
        
        for (auto c : s)
        {
            if (c == 'A')
            {
                absentCounter++;
                if (lateCounter > 0)
                    lateCounter = 0;
            }
            else if (c == 'L')
            {
                lateCounter++;
            }
            else if (c == 'P')
            {
                if (lateCounter > 0)
                    lateCounter = 0;
                
                continue;
            }
            
            if (absentCounter >= 2 || lateCounter >= 3)
            {
                return false;
            }
        }
        
        return true;
    }
};