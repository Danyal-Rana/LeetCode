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
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode *tempHead = new ListNode(0);
        ListNode *tempTail = tempHead;
        
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tempTail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tempTail->next = list2;
                list2 = list2->next;
            }
            tempTail = tempTail->next;
        }
        
        tempTail->next = list1 ? list1 : list2;
        
        ListNode* result = tempHead->next;
        delete tempHead;
        return result;
    }
    
    
    ListNode* sortList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode *tortoise = head;
        ListNode *hare = head;
        
        while (hare->next != NULL and hare->next->next != NULL)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        
        ListNode *head2 = tortoise->next;
        tortoise->next = NULL;
        
        ListNode *left = sortList (head);
        ListNode *right = sortList (head2);
        
        return mergeTwoLists (left, right);
    }
};