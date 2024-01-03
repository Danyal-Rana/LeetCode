class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int m = bank.size();
        int n = bank[0].size();
        
        vector<int> myVector;
        
        for (auto i : bank)
        {
            int x = count (i.begin(), i.end(), '1');
            
            if (x != 0)
            {
                myVector.push_back (x);
            }
        }
        
        int ans = 0;
        
        for (int i=0; i + 1 < myVector.size() ; i++)
        {
            ans += (myVector[i] * myVector[i+1]);
        }
        
        return ans;
    }
};