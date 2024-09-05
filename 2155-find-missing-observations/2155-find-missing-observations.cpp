class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum=0;
        for(auto it:rolls){
            sum+=it;
        }
        int nsum=mean*(n+m)-sum;
        if(nsum<n||nsum>6*n){
            return {};
        }
        int val=nsum/n;

        vector<int>ans;
        for(int i=0;i<n-1;i++){
            ans.push_back(val);
        }
        int p=nsum-(n-1)*val;
        if(p>6){
            ans.push_back(6);
            p=p-6;
            // cout<<p<<endl;
            int q=0;
            while(p>0){
                int req=6-ans[q];
                ans[q]=ans[q]+min(p,req);
                p=max(0,p-req);
                // cout<<p<<endl;
                // cout<<req<<endl;
                q++;
            }
            return ans;
        }

        ans.push_back(nsum-(n-1)*val);
        return ans;
    }
};