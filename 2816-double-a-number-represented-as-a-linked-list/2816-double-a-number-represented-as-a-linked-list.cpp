/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) 
        {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) 
    {
        if (!head)
            return nullptr;
        
        ListNode* reversedHead = reverseList(head);
        
        ListNode* curr = reversedHead;
        
        int carry = 0;
        
        while (curr) 
        {
            int newVal = curr->val * 2 + carry;
            curr->val = newVal % 10;
            carry = newVal / 10;
            if (!curr->next && carry > 0) 
            {
                curr->next = new ListNode(carry);
                break;
            }
            curr = curr->next;
        }
        
        return reverseList(reversedHead);
    }
};
