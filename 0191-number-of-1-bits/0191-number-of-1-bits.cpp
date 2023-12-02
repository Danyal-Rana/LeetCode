class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int myCounter = 0;
        
        while (n != 0)
        {
            if (n & 1)
            {
                myCounter++;
            }
            n = n >> 1;
        }
        
        return myCounter;
    }
};