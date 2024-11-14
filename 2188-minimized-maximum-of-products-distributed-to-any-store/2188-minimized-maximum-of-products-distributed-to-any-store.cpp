class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int m=q.size();
        sort(q.begin(),q.end());
        int ans=q.back();
        int l=1,h=q.back();

        while(l<=h)
        {
            int mid=l+h;
            mid>>=1;
            //mid represent the value we want to check 
            //for the possibility of answer

            int x=n;
            vector<int> qq=q;

            int tot=0,i=0;
            //tot stores the stores needed for the current value of mid

            for(i=0;i<m; )
            {
                qq[i] -= mid;
                tot++;
                //if current product is exhausted then move to next product
                if(qq[i]<=0)
                i++;
            }

            //less than n stores required and complete 
            if(tot <= n)
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }

        return ans;
    }
};