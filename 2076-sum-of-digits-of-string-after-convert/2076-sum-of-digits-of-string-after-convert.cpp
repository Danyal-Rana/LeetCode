class Solution {
public:
    int getLucky(string s, int k)
    {
        int ans = 0;
        string temp;

        for (int i=0; i<s.size(); i++)
        {
            temp += to_string((int)(s[i]-96));
        }

        while (k--)
        {
            ans = 0;

            for (int i=0; i<temp.size(); i++)
            {
                ans += (temp[i]-'0');
            }

            temp = to_string(ans);
        }

        return ans;
    }
};