class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        vector<string> ans;
        
        for (auto w : wordDict)
        {
            if (s.substr(0, w.length()) == w)
            {
                if (w.length() == s.length())
                {
                    ans.push_back(w);
                }
                else
                {
                    vector<string> temp = wordBreak(s.substr(w.length()), wordDict);
                    for (string t : temp)
                    {
                        ans.push_back(w + " " + t);
                    }
                }
            }
        }
        
        return ans;
    }
};