class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        int n = arr.size();
        vector<int> ans;

        vector<int> cumXor (n, 0);
        
        cumXor[0] = arr[0];
        for (int i=1; i<n; i++)
        {
            cumXor[i] = cumXor[i-1] ^ arr[i];
        }

        for (vector<int> &q : queries)
        {
            int left = q[0];
            int right = q[1];

            int xorVal = cumXor[right] ^ (left==0 ? 0 : cumXor[left-1]);

            ans.push_back(xorVal);
        }

        return ans;
    }
};