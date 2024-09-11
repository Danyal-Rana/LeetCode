class Solution {
public:
    int minBitFlips(int start, int goal)
    {
        int counter = 0;
        int differentBit = start ^ goal;

        while (differentBit)
        {
            if (differentBit & 1)
            {
                counter++;
            }
            differentBit = differentBit >> 1;
        }
        
        return counter;
    }
};