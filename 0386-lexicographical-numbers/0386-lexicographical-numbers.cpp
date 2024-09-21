class Solution {
public:

    void helper(int num, int n, vector<int> &ans)
    {
        if (num > n)
            return;

        ans.push_back(num);

        for (int appendNum=0; appendNum <= 9; appendNum++)
        {
            int newNum = num*10 + appendNum;

            if (newNum > n)
            {
                return;
            }
            helper(newNum, n, ans);
        }
    }

    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;

        for (int i=1; i<=9; i++)
        {
            helper(i, n, ans);
        }

        return ans;
    }
};