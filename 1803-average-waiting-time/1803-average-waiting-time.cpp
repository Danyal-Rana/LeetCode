class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waittime=0;
        int time=customers[0][0];
        int n=customers.size();
        for(int i=0;i<n;i++){
            if(customers[i][0]>time){
                time=customers[i][0]+customers[i][1];
            }
            else{
                time+=customers[i][1];
            }           
            waittime+=(time-customers[i][0]);
        }
        return waittime/n;
        
    }
};