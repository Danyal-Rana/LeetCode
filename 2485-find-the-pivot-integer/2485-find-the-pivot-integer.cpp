class Solution {
public:
    int pivotInteger(int n)
    {
        int sum = n * (n+1)/2;
        double x = sqrt (sum);
        
        if (x - ceil(x) == 0)
        {
            return int(x);
        }
        else
        {
            return -1;
        }
    }
};