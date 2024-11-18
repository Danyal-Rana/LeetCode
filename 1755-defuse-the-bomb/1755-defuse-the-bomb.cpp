class Solution {
public:
    void greater(vector<int> &code, int k, vector<int>& ans) 
    {
        int n = code.size();
        for (int i = 0; i < n; i++) 
        {
            int sum = 0;
            for (int j = 1; j <= k; j++) 
            {
                sum += code[(i + j) % n];
            }
            ans[i] = sum;
        }
    }

    void smaller(vector<int> &code, int k, vector<int>& ans) 
    {
        int n = code.size();
        for (int i = 0; i < n; i++) 
        {
            int sum = 0;
            for (int j = 1; j <= -k; j++) 
            { 
                sum += code[(i - j + n) % n];
            }
            ans[i] = sum;
        }
    }

    vector<int> decrypt(vector<int>& code, int k) 
    {
        vector<int> ans(code.size(), 0);
        
        if (k < 0) {
            smaller(code, k, ans);
        }
        else if (k == 0) 
        {
            return ans;
        } 
        else 
        {
            greater(code, k, ans);
        }

        return ans;
    }
};