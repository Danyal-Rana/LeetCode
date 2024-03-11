class Solution {
public:
    string customSortString(string order, string s)
    {
        unordered_map <char, int> oChar;
        string res ;
        
        for (auto i : order)
        {
            oChar[i] = 0;
        }
        
        for (auto i : s)
        {
            if (oChar.find(i) != oChar.end())
            {
                oChar[i]++;
            }
        }
        
        for (auto i : order)
        {
            res.append(oChar[i], i);
        }
        
        for (auto i : s)
        {
            if (oChar.find(i) == oChar.end())
            {
                res.push_back(i);
            }
        }
        
        return res;
        
        
    }
};