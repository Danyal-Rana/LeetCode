class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, ans = 0;
        sort(tokens.begin(),tokens.end());
        int i=0, j=tokens.size()-1;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                ans = max(ans,score);
                power -= tokens[i];
                i++;
            }
            else if(score>0){
                score--;
                power += tokens[j];
                j--;
            }
            else
                return ans;
        }
        return ans;
    }
};