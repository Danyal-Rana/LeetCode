class Solution {
public:
    int maxLength(vector<string>& arr, string str = "", int index = 0)
    {
        unordered_set<char> s (str.begin(), str.end());
        
        if (str.length() != s.size())
            return 0;
        
        int ret = str.length();
        
        for (int i=index; i<arr.size(); i++)
        {
            ret = max (ret, maxLength (arr, str+arr[i], i+1));
        }
        
        return ret;
    }
};