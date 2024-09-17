class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> myMap;
        vector<string> ans;
        string s = "";

        // Process first sentence (s1)
        for (int i = 0; i <= s1.size(); i++) {
            if (i == s1.size() || s1[i] == ' ') {
                if (!s.empty()) {
                    myMap[s]++;
                    s.clear();
                }
            } else {
                s += s1[i];
            }
        }

        // Process second sentence (s2)
        for (int i = 0; i <= s2.size(); i++) {
            if (i == s2.size() || s2[i] == ' ') {
                if (!s.empty()) {
                    myMap[s]++;
                    s.clear();
                }
            } else {
                s += s2[i];
            }
        }

        // Collect words that appear exactly once
        for (const auto& pair : myMap) {
            if (pair.second == 1) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};