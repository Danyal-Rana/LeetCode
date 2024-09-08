/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        ListNode *curr = head;
        int n = 0;

        while (curr)
        {
            n++;
            curr = curr->next;
        }

        int eachBucketNodes = n/k;
        int reminderNodes = n%k;

        vector<ListNode*> ans (k, NULL);
        curr = head;
        ListNode *pre = NULL;

        for (int i=0; i<k; i++)
        {
            ans[i] = curr;

            for (int count=1; count<=eachBucketNodes + (reminderNodes>0 ? 1 : 0); count++)
            {
                pre = curr;
                curr = curr->next;
            }

            reminderNodes--;
            if (pre)
            {
                pre->next = NULL;
            }
        }

        return ans;
    }
};