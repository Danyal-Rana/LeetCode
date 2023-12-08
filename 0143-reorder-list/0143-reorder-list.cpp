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
    void reorderList(ListNode* head)
    {
        if (!head || !head->next || !head->next->next)
        {
            return;
        }
        ListNode *hare = head;
        ListNode *tortoise = head;
        ListNode *prev = NULL;
        
        while ( hare!=NULL && hare->next!=NULL)
        {
            hare = hare->next->next;
            prev = tortoise;
            tortoise = tortoise->next;
        }
        
        prev->next = NULL;
        
        ListNode *head2 = NULL;
        
        while (tortoise != NULL)
        {
            ListNode *t = tortoise->next;
            tortoise->next = head2;
            head2 = tortoise;
            tortoise = t;
        }
        
        hare = head;
        
        while (hare != NULL)
        {
            ListNode *t1 = hare->next;
            hare->next = head2;
            ListNode *t2 = head2->next;
            if (t1 != NULL)
            {
                head2->next = t1;
            }
            
            hare = t1;
            head2 = t2;
        }
    }
};