class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        
        int n = s.size();
        int maxLen = 1;
        int st = 0;
        int end = 0;
        
        for (int i = 0; i < n - 1; i++) 
        {
            int l = i;
            int r = i;
            
            while (l >= 0 && r < n && s[l] == s[r]) 
            {
                if (r - l + 1 > maxLen) 
                {
                    maxLen = r - l + 1;
                    st = l;
                    end = r;
                }
                l--;
                r++;
            }
        }
        
        for (int i = 0; i < n - 1; i++) {
            int l = i;
            int r = i + 1;
            
            while (l >= 0 && r < n && s[l] == s[r]) 
            {
                if (r - l + 1 > maxLen) 
                {
                    maxLen = r - l + 1;
                    st = l;
                    end = r;
                }
                l--;
                r++;
            }
        }
        
        return s.substr(st, maxLen);
    }
};
