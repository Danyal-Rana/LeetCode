class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        vector<int> fre1 (26, 0);
        vector<int> fre2 (26, 0);
        
        vector<int> isPresent1 (26, 0);
        vector<int> isPresent2 (26, 0);
        
        for (auto i : word1)
        {
            fre1[i-'a']++;
            isPresent1[i-'a']=1;
        }
        
        for (auto i : word2)
        {
            fre2[i-'a']++;
            isPresent2[i-'a']=1;
        }
        
        sort (fre1.begin(), fre1.end());
        
        sort (fre2.begin(), fre2.end());
        
        return fre1==fre2 && isPresent1==isPresent2;
    }
};