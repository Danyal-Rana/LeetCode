class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        set<int> w, l;
        unordered_map<int, int> m;
        vector<vector<int>> myVector;
        vector<int> v1, v2;
        
        for (auto i : matches)
        {
            w.insert(i[0]);
            l.insert(i[1]);
            m[i[1]]++;
        }
        
        for (auto i : w)
        {
            if (m.find(i)==m.end())
            {
                v1.push_back (i);
            }
        }
        
        for (auto i : l)
        {
            if (m[i]==1)
            {
                v2.push_back (i);
            }
        }
        
        
        myVector.push_back (v1);
        myVector.push_back (v2);
        
        return myVector;
        
    }
};