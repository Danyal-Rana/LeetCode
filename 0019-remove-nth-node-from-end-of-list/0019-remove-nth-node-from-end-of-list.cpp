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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *dummyHead = new ListNode (0);
        dummyHead->next = head;
        
        ListNode *tortoise = dummyHead;
        ListNode *hare = dummyHead;
        
        for (int i=1; i<=n+1; i++)
        {
            hare = hare->next;
        }
        
        while (hare != NULL)
        {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        
        tortoise->next = tortoise->next->next;
        
        return dummyHead->next;
        
    }
};