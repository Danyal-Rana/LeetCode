class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int teams = (skill.size())/2;
        int sum =0;
        for(auto i:skill){
            sum += i;
        }
        if(sum%teams != 0) return -1;

        int reqSum = sum/teams;

        vector<int>count(1001,0);
        for(auto i:skill){
            count[i]++;
        }

        long long ans=0;
        for(int i=0;i<skill.size();i++){
            int half = reqSum - skill[i];
            if(count[half] > 0){
                ans += skill[i] * half;
                count[half]--;
            }
            else return -1;
        }
        return ans/2;
    }
};