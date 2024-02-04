class Solution {
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
        {
            return "";
        }
        
        unordered_map <char, int> fre_t;
        for (auto i : t)
        {
            fre_t[i]++;
        }
        
        int uniq = fre_t.size();
        int uniqTillNow = 0;
        int ans = INT_MAX;
        
        int l = 0;
        int r = 0;
        int start = 0;
        
        unordered_map <char, int> fre_s;
        
        while (r < s.length())
        {
            fre_s[s[r]]++;
            
            if (fre_t[s[r]] == fre_s[s[r]])
            {
                uniqTillNow++;
            }
            
            while (l<=r && uniqTillNow==uniq)
            {
                if (r-l+1 < ans)
                {
                    start = l;
                    ans = r-l+1;
                }
                
                fre_s[s[l]]--;
                
                if (fre_s[s[l]] < fre_t[s[l]])
                {
                    uniqTillNow--;
                }
                
                l++;
            }
            r++;
        }
        
        return ans == INT_MAX ? "" : s.substr(start, ans);
    }
};