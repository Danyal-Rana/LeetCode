class Solution {
public:
    int minKBitFlips(vector<int>& v, int k) {
        int ans=0,x,n=v.size();
        vector<int> m(n,0);
        for(int i=0;i<n;i++)
        {
            x=0;
            if((i-1)>=0){ x=m[i-1];
            if((i-k)>=0) x=x-m[i-k];}

            if(((x%2)^v[i])==0 )
            {
                if(i>n-k) return -1;
                m[i]=1;
                ans++;
            }
            if(i>0)
            m[i]+=m[i-1];
        }
        return ans;
    }
};