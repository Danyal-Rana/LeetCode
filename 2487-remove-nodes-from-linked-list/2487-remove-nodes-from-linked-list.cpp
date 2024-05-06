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
    
    ListNode *reverse (ListNode *head)
    {
        ListNode *cur = head;
        ListNode *prev = NULL;
        
        while (cur != NULL)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) 
    {
        ListNode *rHead = reverse(head);
        
        int maxValue = rHead->val;
        
        ListNode *temp = rHead;
        
        while (temp->next != NULL)
        {
            if (temp->next->val < maxValue)
            {
                temp->next = temp->next->next;
            }
            else
            {
                maxValue = temp->next->val;
                temp = temp->next;
            }
        }
        
        return reverse(rHead);
    }
};