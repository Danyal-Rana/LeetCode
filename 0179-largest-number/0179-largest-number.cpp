class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        vector<string> strs;
        for (int num : nums) 
        {
            strs.push_back(to_string(num));
        }

        auto myComparator = [](const string& a, const string& b) 
        {
            return a + b > b + a;
        };

        sort(strs.begin(), strs.end(), myComparator);

        if (strs[0] == "0") 
        {
            return "0";
        }

        string ans;
        for (const string& str : strs) 
        {
            ans += str;
        }

        return ans;
    }
};