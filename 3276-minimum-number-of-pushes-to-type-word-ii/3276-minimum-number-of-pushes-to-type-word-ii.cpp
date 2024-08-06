class Solution {
public:
    int minimumPushes(string word)
    {
        unordered_map<char, int> freqMap;
        for (auto c : word)
        {
            freqMap[c]++;
        }

        vector<int> freq;
        for (auto p : freqMap)
        {
            freq.push_back(p.second);
        }
        sort (freq.begin(), freq.end(), greater<int>());

        int ans = 0;
        int cnt = 0;

        for (auto f : freq)
        {
            cnt++;

            if (cnt <= 8)
            {
                ans += 1*f;
            }
            else if (cnt <=16)
            {
                ans += 2*f;
            }
            else if (cnt <= 24)
            {
                ans += 3*f;
            }
            else
            {
                ans += 4*f;
            }
        }

        return ans;
    }
};