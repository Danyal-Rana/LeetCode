class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> myVector (n+1);

        if (n == 0)
        {
            return myVector;
        }
        myVector[0] = 0;

        for (int i=1; i<=n; i++)
        {
            if (i%2==0)
            {
                myVector[i] = myVector[i/2];
            }
            else
            {
                myVector[i] = myVector[i/2]+1;
            }
        }
        return myVector;
    }
};