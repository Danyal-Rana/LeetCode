class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        queue<int> q;
        vector<int> ans;
        
        for (int i=1; i<=9; i++)
        {
            q.push (i);
        }
        
        while (!q.empty())
        {
            int n = q.front();
            
            q.pop();
            
            if (n>=low && n<=high)
            {
                ans.push_back (n);
            }
            
            if (n%10<9)
            {
                int rem = n%10;
                
                q.push ((n*10)+(rem+1));
            }
        }
        
        return ans;
    }
};