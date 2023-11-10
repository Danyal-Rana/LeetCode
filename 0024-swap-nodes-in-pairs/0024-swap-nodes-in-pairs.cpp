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
    ListNode* swapPairs(ListNode* head)
    {
        if (head == NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode *dummyHead = new ListNode (0);
        dummyHead->next = head;
        ListNode *temp = dummyHead;
        
        while (temp->next != NULL && temp->next->next != NULL)
        {
            ListNode *n1 = temp->next;
            ListNode *n2 = n1->next;
            
            temp->next = n2;
            n1->next = n2->next;
            n2->next = n1;
            temp = n1;
        }
        
        
        return dummyHead->next;
        
        
    }
};