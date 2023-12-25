class Solution {
public:
    int numDecodings(string s)
    {
        if (s.length()==0 || s[0]=='0')
            return 0;
        
        if (s.length()==1)
            return 1;
        
        int counter1 = 1;
        int counter2 = 1;
        
        for (int i=1; i<s.length(); i++)
        {
            int d = s[i]-'0';
            int dd = (s[i-1]-'0')*10 + d;
            
            int counter = 0;            
            if (d > 0)
                counter += counter2;
            
            if (dd >=10 && dd <= 26)
                counter += counter1;
            
            counter1 = counter2;
            counter2 = counter;
        }
        
        return counter2;
    }
};