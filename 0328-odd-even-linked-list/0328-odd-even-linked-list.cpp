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
    ListNode* oddEvenList(ListNode* head)
    {
        
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode *oddTail = head;
        ListNode *evenHead = head->next;
        ListNode *evenTail = head->next;
        
        while (evenTail!=NULL && evenTail->next!=NULL)
        {
            oddTail->next = oddTail->next->next;
            oddTail = evenTail->next;
            
            evenTail->next = evenTail->next->next;
            evenTail = oddTail->next;
        }
        
        oddTail->next = evenHead;
        
        return head;
    }
};