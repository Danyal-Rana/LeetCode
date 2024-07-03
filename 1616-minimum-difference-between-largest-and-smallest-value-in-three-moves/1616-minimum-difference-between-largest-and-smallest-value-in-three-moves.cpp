class Solution {
public:
    int minDifference(vector<int>& n) 
    {
        if(n.size()<=4)
        {
            return 0;
        }

        int ans=INT_MAX;
        sort(n.begin(),n.end());

        int w=-1;
        int siz=n.size()-2;
        for(int i=0;i<=3;i++)
        {
            // nxtmin
            int nxtmin = n[w+1];
            // prevmax
            int prevmax = n[siz+w-1];

            ans = min(ans,prevmax-nxtmin);
            w++;
        }
        
        return ans;
    }
};