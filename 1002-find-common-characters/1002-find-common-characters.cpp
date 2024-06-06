class Solution {
public:
    vector<string> commonChars(vector<string>& words)
    {
        vector<int> common(26, INT_MAX);
        vector<string> ans;
        
        for (auto s : words)
        {
            vector<int> myCounter(26,0);
            
            for (auto c : s)
            {
                myCounter[c-'a']++;
            }
            
            for (int i=0; i<26; i++)
            {
                common[i] = min(common[i], myCounter[i]);
            }
        }
        
        for (int i=0; i<26; i++)
        {
            for (int j=0; j<common[i]; j++)
            {
                ans.push_back (string(1, i+'a'));
            }
        }
        
        return ans;
    }
};