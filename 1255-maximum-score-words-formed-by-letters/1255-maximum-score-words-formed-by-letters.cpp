class Solution {
public:
    
    void backTrack(vector<string> &words, vector<int> &score, vector<int> &counter, vector<int>myCounter, int pos, int tempAns, int &ans)
    {
        for (int i=0; i<26; i++)
        {
            if (myCounter[i]>counter[i])
                return;
        }
        
        ans = max(ans, tempAns);
        
        for (int i=pos; i<words.size(); i++)
        {
            for (auto &c : words[i])
            {
                myCounter[c-'a']++;
                tempAns += score[c-'a'];
            }
            
            backTrack (words, score, counter, myCounter, i+1, tempAns, ans);
            
            for (auto &c : words[i])
            {
                myCounter[c-'a']--;
                tempAns -= score[c-'a'];
            }
        }
    }
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        vector<int>counter(26, 0);
        vector<int>myCounter(26, 0);
        
        for (auto i : letters)
        {
            counter[i-'a']++;
        }
        
        int ans = 0;
        
        backTrack(words, score, counter, myCounter, 0, 0, ans);
        
        return ans;
    }
};