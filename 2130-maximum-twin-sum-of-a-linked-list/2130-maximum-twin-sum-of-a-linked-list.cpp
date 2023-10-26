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
    int pairSum(ListNode* head)
    {
        ListNode *dummyHead = new ListNode (0);
        dummyHead->next = head;
        
        ListNode *hare = head;
        ListNode *tortoise = dummyHead;
        
        while (hare!=nullptr && hare->next!=nullptr)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        
        ListNode *head2 = tortoise->next;
        tortoise->next = nullptr;
        
        ListNode *temp = nullptr;
        
        while (head2 != nullptr)
        {
            ListNode *t = head2->next;
            head2->next = temp;
            temp = head2;
            head2 = t;
        }
        
        head2 = temp;
        
        int result = INT_MIN;
        
        while (head2 != nullptr)
        {
            result = max (result, head->val+head2->val);
            head = head->next;
            head2 = head2->next;
        }
        
        return result;
    }
};