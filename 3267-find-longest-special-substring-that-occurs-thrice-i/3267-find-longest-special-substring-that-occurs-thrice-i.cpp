class Solution {
public:
    int maximumLength(string s)
    {
        int n = s.size();
        unordered_map<string, int> mp;

        for(int i=0; i<n; i++)
        {
            string str = "";
            for (int j=i; j<n; j++)
            {
                if (str.empty() || str.back()==s[j])
                {
                    str.push_back(s[j]);
                    mp[str]++;
                }
                else
                {
                    break;
                }
            }
        }

        int ans = 0;
        for (auto &it : mp)
        {
            string key = it.first;
            int count = it.second;
            if (count>=3 && key.size()>ans)
            {
                ans = key.size();
            }
        }

        return ans==0 ? -1 : ans;
    }
};