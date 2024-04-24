class Solution {
public:
    
    int helper(int n, vector<int> &myVector)
    {
        if (myVector[n] != -1)
        {
            return myVector[n];
        }
        
        myVector[n] = helper(n-3, myVector)+helper(n-2, myVector)+helper(n-1, myVector);
        
        return myVector[n];
    }
    
    
    int tribonacci(int n)
    {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        
        vector<int> myVector(n+1, -1);
        myVector[0] = 0;
        myVector[1] = 1;
        myVector[2] = 1;
        
        return helper(n, myVector);
    }
};