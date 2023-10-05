class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        if (n==0)
        {
            return true;
        }
        
        int myCounter = 0;
        
        for (int i=0; i<flowerbed.size(); i++)
        {
            if (flowerbed[i]==0)
            {
                int pre = (i==0) ? 0 : flowerbed[i-1];
                int next = (i == flowerbed.size()-1) ? 0 : flowerbed[i+1];
                
                if (pre==0 && next==0)
                {
                    flowerbed[i] = 1;
                    myCounter++;
                }
            }
        }
        
        return myCounter>=n;
    }
};