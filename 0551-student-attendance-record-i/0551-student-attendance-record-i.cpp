class Solution {
public:
    bool checkRecord(string s)
    {
        int myAbsent = 0;
        int myLate = 0;
        
        for (auto c : s)
        {
            if (c == 'A')
            {
                myAbsent++;
                if (myLate > 0)
                    myLate = 0;
            }
            else if (c == 'L')
            {
                myLate++;
            }
            else if (c == 'P')
            {
                if (myLate > 0)
                    myLate = 0;
                
                continue;
            }
            
            if (myAbsent >= 2 || myLate >= 3)
            {
                return false;
            }
        }
        
        return true;
    }
};