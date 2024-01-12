class Solution {
public:
    
    bool isVowel (char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||  c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    
    bool halvesAreAlike(string s)
    {
        int first = 0;
        int second = 0;
        int n = s.size();
        
        for (int i=0; i<n; i++)
        {
            if (isVowel(s[i]) && i<n/2)
                first++;
            else if (isVowel(s[i]) && i>=n/2)
                second++;
        }
        
        return first==second;
    }
};