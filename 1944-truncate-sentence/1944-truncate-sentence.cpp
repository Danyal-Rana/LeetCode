class Solution {
public:
    string truncateSentence(string s, int k) {
        int count=0;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                count++;
            }
            if(count==k)
            {
                break;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};