class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        vector<pair<int, string>> myVector;
        
        for (int i=0; i<names.size(); i++)
        {
            myVector.push_back (make_pair(heights[i], names[i]));
        }
        
        sort (myVector.rbegin(), myVector.rend());
        
        vector<string> ans;        
        for (int i=0; i<myVector.size(); i++)
        {
            ans.push_back (myVector[i].second);
        }
        return ans;
    }
};