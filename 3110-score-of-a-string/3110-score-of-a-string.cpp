class Solution {
public:
    int scoreOfString(string s)
    {
        int score = 0;
        
        for (int i=1; i<s.size(); i++)
        {
            score = score + abs( (s[i-1]-'a') - (s[i]-'a') );
        }
        
        return score;
    }
};