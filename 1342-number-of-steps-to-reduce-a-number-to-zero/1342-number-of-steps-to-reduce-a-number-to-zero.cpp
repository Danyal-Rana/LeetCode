class Solution {
public:
    int numberOfSteps(int num)
    {
        int myCounter = 0;
        
        while (num != 0)
        {
            if (num%2 == 0)
            {
                num /= 2;
                myCounter++;
            }
            else if (num%2 == 1)
            {
                num -= 1;
                myCounter++;
            }
        }
        
        return myCounter;
    }
};