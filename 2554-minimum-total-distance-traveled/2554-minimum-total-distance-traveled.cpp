class Solution {
public:
    long long minDistFind(int currRobo, int currFact, vector<int>& robot, vector<int> &flattenFact, vector<vector<long long>> &dp){

        if(currRobo == robot.size()) return 0;

        if(currFact == flattenFact.size()) return 1e12;

        if(dp[currRobo][currFact] != -1) return dp[currRobo][currFact];

        long long fix = abs(robot[currRobo] -flattenFact[currFact]) + minDistFind(currRobo + 1, currFact + 1,robot,flattenFact,dp );

        long long skip = minDistFind(currRobo, currFact + 1,robot,flattenFact,dp );

        return dp[currRobo][currFact] = min(fix,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<int> flattenFact;

        for(auto &fact: factory){
            for(int i=0;i<fact[1];i++){
                flattenFact.push_back(fact[0]);
            }
        }

        vector<vector<long long>> dp(robot.size(),vector<long long>(flattenFact.size(),-1));

        return minDistFind(0,0,robot,flattenFact, dp);
    }
};