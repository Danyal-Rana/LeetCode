class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head)
    {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        
        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        ListNode *temp = head;
        
        while (left <= right && top <= down && temp != nullptr)
        {
            for (int i = left; i <= right && temp != nullptr; i++)
            {
                ans[top][i] = temp->val;
                temp = temp->next;
            }
            top++;
            
            for (int i = top; i <= down && temp != nullptr; i++)
            {
                ans[i][right] = temp->val;
                temp = temp->next;
            }
            right--;
            
            if (top <= down)
            {
                for (int i = right; i >= left && temp != nullptr; i--)
                {
                    ans[down][i] = temp->val;
                    temp = temp->next;
                }
                down--;
            }
            
            if (left <= right)
            {
                for (int i = down; i >= top && temp != nullptr; i--)
                {
                    ans[i][left] = temp->val;
                    temp = temp->next;
                }
                left++;
            }
        }
        
        return ans;
    }
};