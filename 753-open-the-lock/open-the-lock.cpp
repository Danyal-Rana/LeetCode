class Solution {
public:
    int openLock(vector<string>& deadends, string target1) {
        vector<int> visited(10000,0);
        for(int i=0;i<deadends.size();i++)
        {   
            int cur=stoi(deadends[i]);
            if(cur==0) return -1;
            visited[cur]=-1;
        }
        queue<int> q;
        int target=stoi(target1);
        if(target==0) return 0;
        q.push(0);
        visited[0]=1;
        int ans=0;
        while(!q.empty())
        {   
            ans++;
            int n=q.size();
            while(n--)
            {
                int x=q.front();
                q.pop();
                int y=x;
                for(int i=0;i<4;i++)
                {   
                    int z1=x;
                    int z2=x;
                    int z=y%10;
                    y=y/10;
                    int zp,zn;
                    zp=z+1;
                    zn=z-1;
                    if(z==0) zn=9;
                    if(z==9) zp=0;
                    z1=z1-z*pow(10,i);
                    z2=z2-z*pow(10,i);
                    z1+=zp*pow(10,i);
                    z2+=zn*pow(10,i);
                    if(z1==target||z2==target) return ans;
                    if(visited[z1]==0)
                    {
                        q.push(z1);
                        visited[z1]=1;
                    }
                    if(visited[z2]==0)
                    {
                        q.push(z2);
                        visited[z2]=1;
                    }
                }
            }
        }
        return -1;
    }
};