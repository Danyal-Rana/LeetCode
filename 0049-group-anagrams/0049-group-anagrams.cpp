class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map <string, vector<string> > myMap;

        int n = strs.size();
        string temp;

        for (int i=0; i<n; i++)
        {
            temp = strs[i];
            sort (strs[i].begin(), strs[i].end());
            myMap[strs[i]].push_back(temp);
        }

        vector <vector<string>> myResult;

        for (auto itr=myMap.begin(); itr!=myMap.end(); itr++)
        {
            myResult.push_back(itr->second);
        }

        return myResult;
    }
};