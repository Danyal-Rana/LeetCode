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
    ListNode* deleteMiddle(ListNode* head)
    {
        ListNode *dummyHead = new ListNode (0);
        dummyHead->next = head;
        ListNode *tortoise = dummyHead;
        ListNode *hare = head;

        while (hare!=NULL && hare->next!=NULL)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }

        tortoise->next = tortoise->next->next;

        return dummyHead->next;
    }
};