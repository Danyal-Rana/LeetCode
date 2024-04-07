class Solution {
public:
    
    void helper (string digits, vector<string>&ans, string nums[], int i, string s)
    {
        if (i == digits.size())
        {
            ans.push_back(s);
            return;            
        }
        
        string val = nums[digits[i]-'0'];
        
        for (int j=0; j<val.size(); j++)
        {
            helper (digits, ans, nums, i+1, s+val[j]);
        }
    }
    
    
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        
        if (digits.size()==0)
        {
            return ans;
        }
        
        string nums[10] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        helper (digits, ans, nums, 0, "");
        
        return ans;
    }
};